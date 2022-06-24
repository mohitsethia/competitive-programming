#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
using ll = long long;
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> f[m+1], ans(m+1);
    vector<pair<ll, ll> > sz;
    ll x, frnd;
    for(ll i = 1; i <= m; i++){
        cin >> x;
        for(ll j = 0; j < x; j++){
            cin >> frnd;
            f[i].emplace_back(frnd);
        }
        sz.emplace_back(make_pair(x, i));
    }
    sort(sz.begin(), sz.end());
    map<ll, ll> mp;
    for(ll i = 0; i < (ll)sz.size(); i++){
        for(ll j = 0; j < (ll)f[sz[i].second].size(); j++){
            if(mp[f[sz[i].second][j]] < (m+1)/2){
                mp[f[sz[i].second][j]]++;
                ans[sz[i].second] = f[sz[i].second][j];
                break;
            }
        }
    }
    for(ll i = 1; i <= m; i++){
        if(ans[i] == 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(ll i = 1; i <= m; i++){
        cout << ans[i] << " \n"[i == m];
    }
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
