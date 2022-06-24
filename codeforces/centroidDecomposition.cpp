#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N = 1e5+1;
set<int> g[N];
int n, nodes = 0;
int subtree[N], centroidParent[N];
void dfs(int z, int p){
    nodes++;
    subtree[z] = 1;
    for(auto it: g[z]){
        if(it == p) continue;
        dfs(it, z);
        subtree[z] += subtree[it];
    }
}
int centroid(int z, int p){
    for(auto it: g[z]){
        if(it == p) continue;
        if(subtree[it] > (nodes >> 1)){
            return centroid(it, z);
        }
    }
    return z;
}
void decompose(int z, int p){
    nodes = 0;
    dfs(z, z);
    int node = centroid(z, z);
    centroidParent[node] = p;
    for(auto it: g[node]){
        g[it].erase(node);
        decompose(it, node);
    }
}
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    decompose(1, -1);
    for(int i = 1; i <= n; i++){
        cout << "Par[" << i << "] = " << centroidParent[i] << "\n";
    }
    return 0;
}
