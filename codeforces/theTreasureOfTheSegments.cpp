#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll, ll> > a(n);
        vector<ll> l(n), r(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
            l[i] = a[i].first;
            r[i] = a[i].second;
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        ll ans = n-1;
        for(ll i = 0; i < n; i++){
            ll left = lower_bound(r.begin(), r.end(), a[i].first)- r.begin();
            ll right = max(0ll, n-(int)(upper_bound(l.begin(), l.end(), a[i].second) - l.begin()));
            ans = min(ans, left+right);
        }
        cout << ans << "\n";
    }
    return 0;
}
