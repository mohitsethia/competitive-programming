#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
const int N = 2e6+5;
ll dp[N] = {0};
void precompute(){
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 4;
    for(int i = 4; i < N; i++){
        dp[i] = (dp[i-1] + 2*dp[i-2] + ((i%3 == 0) ? 4 : 0))%mod;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        cout << dp[n]%mod << '\n';
    }
    return 0;
}
