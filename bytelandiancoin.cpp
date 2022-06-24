#include<iostream>
#include<map>
using namespace std;
#define ll long long int
map<ll, ll> dp;
ll solve(ll n){
    if(n == 0){
        return 0;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    ll a = solve(n/2) + solve(n/3) + solve(n/4);
    if(a > n){
        dp[n] = a;
    }
    else{
        dp[n] = n;
    }
    return dp[n];
}
int main(){ 
    ll n;
    dp[0] = 0;
    while(cin >> n){
//        if(dp[n] != 0){
//            cout << dp[n] << endl;
//            continue;
//        }
//        for(ll i = 1; i <= n; i++){
//            dp[i] = max(i, dp[i/2]+dp[i/3]+dp[i/4]);
//        }
//        cout << dp[n] << endl;
        ll ans = solve(n);
        cout << ans << endl;
    }
    return 0;
}
