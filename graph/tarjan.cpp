#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<cstring>
using namespace std;
int n;
map<int, vector<int> > g;
void dfs(int u, vector<int> &discoveryTime, vector<int> &low, vector<int> & parent, vector<pair<int, int> > &Bridges){
    static int timer = 0;
    discoveryTime[u] = low[u] = timer;
    timer++;
    for(int v: g[u]){
        if(discoveryTime[v] == -1){
            parent[v] = u;
            dfs(v, discoveryTime, low, parent, Bridges);
            low[u] = min(low[u], low[v]);
            if(low[v] > discoveryTime[u]){
                Bridges.push_back({u, v});
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], discoveryTime[v]);
        }
    }
}
   
void findBridges_Tarjan(){
    vector<int> discoveryTime(n, -1), low(n, -1), parent(n, -1);
    vector<pair<int, int> > Bridges;
    for(int i = 0; i < n; i++){
        if(discoveryTime[i] == -1){
            dfs(i, discoveryTime, low, parent, Bridges);
        }
    }
    cout << "Bridges are: \n";
    for(auto it: Bridges){
        cout << it.first << " " << it.second << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    findBridges_Tarjan();
    return 0;
}
