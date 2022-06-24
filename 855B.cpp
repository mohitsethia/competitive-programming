#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, p, q, r;
    cin >> n >> p >> q >> r;
    vector<ll> a(n);
    vector<vector<ll > > dp(n+1, vector<ll>(3, 0));
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0][0] = p*a[0];
    dp[0][1] = dp[0][0] + q*a[0];
    dp[0][2] = dp[0][1] + r*a[0];
    for(ll i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][0], p*a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i][0] + q*a[i]);
        dp[i][2] = max(dp[i-1][2], dp[i][1] + r*a[i]);
    }
    cout << dp[n-1][2] << endl;
    return 0;
}
