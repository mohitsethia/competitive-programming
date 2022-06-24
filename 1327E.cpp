#include<iostream>
#include<algorithm>

#define int long long

using namespace std;

const int MOD = 998'244'353;
const int N = 2e5+1;

signed main(){
    int fact[N];
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = fact[i-1]*10;
        fact[i] %= MOD;
    }
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int ans = 2*10*9*fact[n-i-1] % MOD;
        ans += (n-i-1)*10*9*9*fact[n-i-2] % MOD;
        cout << ans%MOD << " ";
    }
    cout << "10\n";
    return 0;
}
