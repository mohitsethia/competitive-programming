#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n+1, 0), g[n+1];
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        indegree[v]++;
        g[u].emplace_back(v);
    }
    vector<bool> visited(n+1, false);
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
            visited[i] = true;
        }
    }
    vector<int> res;
    while(!q.empty()){
        int curr = q.top();
        res.emplace_back(curr);
        q.pop();
        for(auto it: g[curr]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(indegree[i] > 0){
            cout << "Sandro fails.\n";
            return 0;
        }
    }
    for(auto it: res){
        cout << it << " ";
    }
    return 0;
}
