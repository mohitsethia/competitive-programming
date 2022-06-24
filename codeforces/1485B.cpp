#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a(n+1);
    vector<ll> pref(n+2);
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(ll i = 2; i <= n; i++){
        pref[i] = a[i]-a[i-1];
        pref[i] = 2*(pref[i]-1);
    }
    for(ll i = 1; i <= n; i++){
        pref[i] += pref[i-1];
    }
    while(q--){
        ll ans = 0, l, r;
        cin >> l >> r;
        ans = (pref[r]-pref[l]);
        ans += a[l]-1;
        ans += k-a[r];
        cout << ans << "\n";
    }
    return 0;
}
