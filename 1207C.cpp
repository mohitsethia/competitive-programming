#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        vector<vector<ll> > dp(n+1, vector<ll>(2, 1e18));
        dp[0][0] = b;
        for(ll i = 0; i < n; i++){
            if(s[i] == '0'){
                dp[i+1][0] = dp[i][0] + a+b;
                dp[i+1][1] = dp[i][0] + 2ll*(a+b);
                dp[i+1][0] = min(dp[i+1][0], dp[i][1] + 2ll*a + b);
            }
                dp[i+1][1] = min(dp[i+1][1], dp[i][1]+a + 2ll*b);
        }
        cout << dp[n][0] << "\n";
    }
    return 0;
}
