#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n;

vector<int> bfs(vector<vector<int> > &edges){
    queue<pair<int, int> > q;
    q.push({0, 0});
    vector<int> dist(n, -1);
    dist[0] = 0;
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        for(int v: edges[temp.first]){
            if(dist[v] == -1){
                dist[v] = temp.second+1;
                q.push({v, dist[v]});
            }
        }
    }
    return dist;
}

int dfs(int u, vector<vector<int> > &edges, vector<bool> &vis, vector<int> &dist, vector<int> &newDist){
    if(vis[u]) return newDist[u];
    vis[u] = true;
    for(auto v: edges[u]){
        if(dist[u] < dist[v]){
            newDist[u] = min(newDist[u], dfs(v, edges, vis, dist, newDist));
        }
    }
    return newDist[u];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        vector<vector<int> > edges(n);
        while(m--){
            int u, v;
            cin >> u >> v;
            --u, --v;
            edges[u].push_back(v);
        }
        vector<int> dist = bfs(edges);
        vector<int> newDist = dist;
        for(int u = 0; u < n; u++){
            for(int v: edges[u]){
                newDist[u] = min(newDist[u], dist[v]);
            }
        }
        vector<bool> vis(n, false);
        for(int u = 0; u < n; u++){
            dfs(u, edges, vis, dist, newDist);
        }
        for(int d: newDist){
            cout << d << " ";
        }
        cout << "\n";
    }
    return 0;
}
