#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
const ll N = (ll)2e5 + 2;
ll a[N], b[N];
ll func(vector<ll> &aa, vector<ll> &bb){
    ll n = (ll)aa.size();
    ll m = (ll)bb.size();
    vector<ll> sum(m+10);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        mp[aa[i]] = 1ll;
    }
    for(ll i = m-1; i >= 0; i--){
        sum[i] = sum[i+1]+mp[bb[i]];
    }
    ll res = sum[0];
    for(ll i = 0; i < m; i++){
        ll up = upper_bound(aa.begin(), aa.end(), bb[i]) - aa.begin();
        ll pos = lower_bound(bb.begin(), bb.end(), bb[i]-up+1ll) - bb.begin();
        res = max(res, i-pos+1ll+sum[i+1]);
    }
    return res;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> az, af, bz, bf;
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0){
                az.emplace_back(a[i]);
            }
            else{
                af.emplace_back(-1ll*a[i]);
                // cout << af.back() << "\n";
            }
        }
        for(ll i = 0; i < m; i++){
            cin >> b[i];
            if(b[i] > 0){
                bz.emplace_back(b[i]);
            }
            else{
                bf.emplace_back(-1ll*b[i]);
                // cout << bf.back() << "\n";
            }
        }
        reverse(af.begin(), af.end());
        reverse(bf.begin(), bf.end());
        cout << (func(az, bz) + func(af, bf)) << "\n";
    }
    return 0;
}
