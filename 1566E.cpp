#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

const int N = 2e5+1;

vector<int> adj[N];
int leaf[N];

void dfs(int src = 1, int par = 0){
    leaf[src] = 1;
    for(int to: adj[src]){
        if(to != par){
            dfs(to, src);
            if(leaf[to]) leaf[src] = 0;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs();
        int lf = 0, bud = 0;
        for(int i = 2; i <= n; i++){
            if(leaf[i]) lf++;
            else bud++;
        }
        bool leaf_root = true;
        for(int i: adj[1]){
            if(leaf[i]){
                leaf_root = false;
                break;
            }
        }
        cout << lf-bud+leaf_root << "\n";
    }
    return 0;
}
