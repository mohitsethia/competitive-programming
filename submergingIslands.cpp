#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
vector<int> mp[10001];
vector<bool> vis(10001, false);
vector<int> discovery(10001, -1), low(10001, -1);
set<int> st;
int timer;
void dfs(int src, int par){
    int children = 0;
    vis[src] = true;
    discovery[src] = low[src] = timer++;
    for(auto it: mp[src]){
        if(it == par) continue;
        if(vis[it]){
            low[src] = min(low[src], discovery[it]);
        }
        else{
            dfs(it, src);
            low[src] = min(low[src], low[it]);
            if(low[it] >= discovery[src] && par != -1){
                st.insert(src);;
            }
            children++;
        }
    }
    if(par == -1 && children > 1){
        st.insert(src);
    }
}
void tarjan(int n){
    timer = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    int articulationPoints = (int)st.size();
    cout << articulationPoints << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= n; i++){
            mp[i].clear();
            vis[i] = false;
        }
        st.clear();
        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            mp[u].emplace_back(v);
            mp[v].emplace_back(u);
        }
        tarjan(n);
    }
    return 0;
}
