#include<iostream>
#include<algorithm>

using namespace std;

#define int long long
#define mod 1000000007

const int N = 2e5+1;

int fact[N];

void preprocess(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i += 1){
        fact[i] = fact[i-1]*i%mod;
    }
}

void solve(){
    int n;
    cin >> n;
    int res = n*fact[2*n-1]%mod;
    cout << res << "\n";
}

int32_t main(){
    preprocess();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
