#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
#define mk make_pair
typedef pair<int, int> pi;
typedef pair<int, pair<int, int> > pii;
typedef long long ll;

int dfs(int src, vector<int> *graph, vector<bool>& visited, vector<int>& ans){
    for(int i = 0; i < (int)graph[src].size(); i++){
        int dest = graph[src][i];
        if(!visited[dest]){
            visited[dest] = true;
            ans[src] += dfs(dest, graph, visited, ans);
            visited[dest] = false;
        }
    }
    ans[src]++;
    return ans[src];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n%2){
        cout << "-1\n";
    }
    else{
        vector<int> graph[n+1];
        int u, v;
        for(int i = 0; i < n-1; i++){
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        vector<bool> visited(n+1);
        vector<int> ans(n+1);
        visited[1] = true;
        int cnt = 0;
        dfs(1, graph, visited, ans);
        for(int i = 1; i <= n; i++){
            if(ans[i]%2 == 0){
                cnt++;
            }
        }
        cout << cnt-1 << endl;
    }
    return 0;
}
