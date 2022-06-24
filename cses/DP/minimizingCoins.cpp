#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
typedef long long ll;
#define endl '\n'
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    cin >> n >> s;
    vector<ll> coins(n);
    for(ll i  = 0; i < n; i++){
        cin >> coins[i];
    }
    vector<ll> dp(s+1, INT_MAX);
    dp[0] = 0;
    for(ll i = 1; i <= s; i++){
        for(ll j = 0; j < n; j++){
            if(i - coins[j] >= 0){
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
    }
    cout << ((dp[s] == INT_MAX) ? -1 : dp[s]) << endl;
    return 0;
}
