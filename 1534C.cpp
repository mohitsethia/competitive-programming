#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int N = 4e5+1;
const int MOD = 1e9+7;
bool vis[N];
ll a[N];
ll b[N];
vector<ll> g[N];
void dfs(ll u){
    vis[u] = true;
    for(auto v: g[u]){
        if(!vis[v]) dfs(v);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
            g[i].clear();
            vis[i] = false;
        }
        for(ll i = 1; i <= n; i++){
            cin >> b[i];
            g[a[i]].emplace_back(b[i]);
            g[b[i]].emplace_back(a[i]);
        }
        ll ans = 1ll;
        for(ll i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                ans = (ans * 2ll) % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
