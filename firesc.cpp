#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e9 + 7ll;
void dfs(ll u, map<ll, vector<ll> > &mp, vector<bool> &visited, ll &employees_in_components){
    visited[u] = true;
    employees_in_components++;
    for(auto it: mp[u]){
        if(!visited[it]){
            dfs(it, mp, visited, employees_in_components);
        }
    }
}
void solve(){
    ll n, m;
    cin >> n >> m;
    map<ll, vector<ll> > mp;
    ll u, v;
    for(ll i = 0; i < m; i++){
        cin >> u >> v;
        mp[u].emplace_back(v);
        mp[v].emplace_back(u);
    }
    ll ans = 1ll;
    ll employees_in_components = 0;
    vector<bool> visited(n+1, false);
    ll fire_escape = 0;
    for(ll i = 1; i <= n; i++){
        employees_in_components = 0;
        if(!visited[i]){
            dfs(i, mp, visited, employees_in_components);
            (ans *= employees_in_components) %= MOD;
            fire_escape++;
        }
    }
    cout << fire_escape << " " << ans << "\n";
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
