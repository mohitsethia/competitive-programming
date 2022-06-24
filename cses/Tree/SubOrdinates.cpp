#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+1;
int n;
vector<int> g[N];
int subtree[N];
void dfs(int z, int p){
    subtree[z] = 1;
    for(auto it: g[z]){
        if(it == p) continue;
        dfs(it, z);
        subtree[z] += subtree[it];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int v;
    for(int u = 2; u <= n; u++){
        cin >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        cout << subtree[i]-1 << ' ';
    }
    return 0;
}
