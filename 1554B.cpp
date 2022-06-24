#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector< ll > a(n);
        // for(ll i = 0; i < n; i++){
            // cin >> a[i];
        // }
        for(auto &x: a){
            cin >> x;
        }
        ll left = max(0ll, n-2*k-1);
        ll ans = LLONG_MIN;
        for(ll i = left; i < n; i++){
            for(ll j = i+1; j < n; j++){
                ans = max(ans, (i+1)*(j+1)*1ll - 1ll*k*(a[i]|a[j]));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
