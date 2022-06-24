#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll x;
        vector<ll> mp(m);
        for(ll i = 0; i < n; i++){
            cin >> x;
            ll r = x%m;
            mp[r]++;
        }
        ll ans = (mp[0] > 0 ? 1 : 0);
        for(ll i = 1; i < m; i++){
            if(m-i < i) break;
            if(m-i == i && mp[i]){
                ans++;
            }
            else{
                if(mp[i] == 0 && mp[m-i] == 0) continue;
                if(mp[i] == mp[m-i]){
                    ans++;
                }
                else{
                    ans += abs(mp[i]-mp[m-i]);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
