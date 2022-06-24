#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
ll cnt = 0;
void dfs(int src, map<int, vector<int> >& adj, vector<bool>& visited){
    visited[src] = true;
    for(auto next: adj[src]){
        if(!visited[next]){
            cnt++;
            dfs(next, adj, visited);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v;
    map<int, vector<int> > mp;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        vector<bool> visited(n+1, false);
        dfs(i, mp, visited);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
