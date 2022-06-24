#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int N = 1e5 + 2;
int n;
set<int> g[N];
int subtree[N];
int total_nodes = 0;
char ans[N];
void dfs(int k, int p){
    total_nodes++;
    subtree[k] = 1;
    for(auto it: g[k]){
        if(it == p) continue;
        dfs(it, k);
        subtree[k] += subtree[it];
    }
}
int centroid(int k, int p){
    for(auto it: g[k]){
        if(it == p) continue;
        if(subtree[it] > (total_nodes >> 1))
            return centroid(it, k);
    }
    return k;
}
void decompose(int k, char ch){
    total_nodes = 0;
    dfs(k, k);
    int node = centroid(k, k);
    ans[node] = ch;
    for(auto it: g[node]){
        g[it].erase(node);
        decompose(it, ch+1);
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
    decompose(1, 'A');
    for(int i = 1; i <= n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
