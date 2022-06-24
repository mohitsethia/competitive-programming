#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> cnt(62);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            for(ll j = 0; j < 61; j++){
                if((a[i] >> j)&1ll){
                    cnt[j]++;
                }
            }
        }
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            ll Or = 0ll, And = 0ll;
            for(ll j = 0; j < 61; j++){
                if((a[i] >> j)&1ll){
                    Or += (1ll << j)%MOD * n;
                    And += (1ll << j)%MOD * cnt[j];
                }
                else{
                    Or += (1ll << j)%MOD * cnt[j];
                }
            }
            Or %= MOD;
            And %= MOD;
            (ans += Or*And) %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
