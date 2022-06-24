#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int MOD = 1e9+7;
const int N = 1e6+1;

int factinv[N];
int naturalinv[N];
int fact[N];

void InverseOfNumber(){
    naturalinv[0] = naturalinv[1] = 1;
    for(int i = 2; i < N; i++){
        naturalinv[i] = naturalinv[MOD % i] * (MOD - MOD/i) % MOD;
    }
}

void InverseOfFactorial(){
    factinv[0] = factinv[1] = 1;
    for(int i = 2; i < N; i++){
        factinv[i] = (naturalinv[i] * factinv[i-1])%MOD;
    }
}

void factorial(){
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = (fact[i-1]*i) % MOD;
    }
}

int Choose(int n, int r){
    if(n < r) return 0;
    int ans = ((fact[n] * factinv[r])%MOD * factinv[n-r])%MOD;
    return ans;
}

int32_t main(){
    InverseOfNumber();
    InverseOfFactorial();
    factorial();
    int n, m;
    cin >> n >> m;
    n--;
    m *= 2;
    cout << Choose(n+m, m) << "\n";
    return 0;
}
