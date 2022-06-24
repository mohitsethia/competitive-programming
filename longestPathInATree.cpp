#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
void dfs(int src, int d, map<int, vector<int> > &g, vector<bool> &visited, int &maxDistance, int &maxNode){
    visited[src] = true;
    if(d > maxDistance){
        maxDistance = d, maxNode = src;
    }
    for(auto it: g[src]){
        if(!visited[it]){
            dfs(it, d+1, g, visited, maxDistance, maxNode);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<int> > g;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<bool> visited(n+1, false);
    int maxDistance = -1, maxNode = -1;
    dfs(1, 0, g, visited, maxDistance, maxNode);
    visited = vector<bool>(n+1, false);
    dfs(maxNode, 0, g, visited, maxDistance, maxNode);
    cout << maxDistance << "\n";
    return 0;
}
