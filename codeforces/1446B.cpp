#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    ll ans = 0;
    vector<vector<ll> > dp(n+1, vector<ll>(m+1));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2ll);
            }
            else{
                dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]) - 1ll);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
