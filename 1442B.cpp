#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll MOD = (ll)998244353;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), where(n+1, -1), cnt(n+1, 1);
        vector<ll> b(k);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            where[a[i]] = i;
        }
        for(ll j = 0; j < k; j++){
            cin >> b[j];
            cnt[where[b[j]]]++;
        }
        ll ans = 1;
        for(ll i = 0; i < k; i++){
            ll now = b[i];
            ll pos = where[now];
            ll c = 0;
            if(pos -1 >= 0 && cnt[pos-1] == 1){
                c++;
            }
            if(pos+1 < n && cnt[pos+1] == 1){
                c++;
            }
            if(c == 0){
                ans = 0;
                break;
            }
            if(c == 2){
                (ans += ans) %= MOD;
            }
            cnt[pos]--;
        }
        cout << ans << "\n";
    }
    return 0;
}
