#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MOD = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    cin >> n >> s;
    vector<ll> coins(n), dp(s+1, 0);
    for(ll i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0] = 1;
    sort(coins.begin(), coins.end());
    for(ll i = 1; i <= s; i++){
        for(ll j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                    dp[i] += dp[i-coins[j]];
            }
            else{
                break;
            }
        }
        dp[i] %= MOD;
    }
    cout << dp[s] << endl;
    return 0;
}
