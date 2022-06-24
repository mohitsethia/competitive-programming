#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
void solve(){
    ll n, c;
    cin >> n >> c;
    vector<ll> dp(n);
    vector<ll> a(n), b(n);
    if(c < a[0]){
        cout << "1\n";
        return;
    }
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; i++){
        cin >> b[i];
    }
    vector<ll> pref(n);
    ll x1 = 0, x = 0, last = 0;
    for(ll i = 0; i < n; i++){
        dp[i] = (i > 0 ? pref[i-1] : 0) + (max(0ll, c-last+a[i]-1))/a[i];
        x1 = max(0ll, b[i]-last+a[i]-1)/a[i];
        pref[i] = (i > 0 ? pref[i-1] : 0) + x1 + 1;
        last += a[i]*x1 -b[i];
    }
    ll mn = 1e18;
    x = 1;
    for(ll i = 0; i < n; i++){
        mn = min(mn, dp[i]);
    }
    cout << mn << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
