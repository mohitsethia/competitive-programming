#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<numeric>
#include<iomanip>

#define pb push_back
#define mk make_pair

using namespace std;
using ll = long long;

typedef pair<ll, ll> pi;
typedef vector<ll> vi;

const ll N = 5005;

vi graph[N];
ll n;
bool possible[N], local[N];
ll dfs(ll src, ll par){
    ll sz = 1;
    vi sizes;
    for(ll &to: graph[src]){
        if(to == par) continue;
        ll tmp = dfs(to , src);
        sz += tmp;
        sizes.pb(tmp);
    }
    if(!sizes.empty()){
        if(par != 0){
            sizes.pb(n-sz);
        }
        for(ll i = 1; i <= n; i++){
            local[i] = false;
        }
        local[0] = true;
        for(ll &x: sizes){
            //not pick

            //pick
            for(ll i = n-x; i >= 0; i--){
                if(local[i]){
                    local[x+i] = true;
                    possible[x+i] = true;
                }
            }
        }
    }
    return sz;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ll u, v;
    for(ll i = 1; i < n; i++){
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1, 0);
    vi ans;
    for(ll i = 1; i <= n-2; i++){
        if(possible[i]){
            ans.pb(i);
        }
    }
    cout << (ll)ans.size() << "\n";
    for(ll &x: ans){
        cout << x << " " << n-x-1 << "\n";
    }
    return 0;
}
