#include<iostream>
#include<algorithm>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<climits>
using namespace std;
void solve(){
    int n, m, x, y;
    cin >> n >> m;
    vector<vector<int> > graph(n+1);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    set<pair<int, int> > s;
    s.insert({0, 1});
    while(!s.empty()){
        auto p = *(s.begin());
        s.erase(s.begin());
        int node = p.second;
        int nodeDist = p.first;
        for(auto child: graph[node]){
            if(nodeDist + 1 < dist[child]){
                if(s.find({dist[child], child}) != s.end()){
                    s.erase({dist[child], child});
                }
                dist[child] = nodeDist+1;
                s.insert({dist[child], child});
            }
        }
    }
    cout << dist[n] << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
