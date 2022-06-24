#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
bool isBipartite(map<int, vector<int> >& mp, int v, vector<bool>& visited, vector<int>& color){
    for(auto u: mp[v]){
        if(!visited[u]){
            visited[u] = true;
            color[u] = 1-color[v];            
            if(!isBipartite(mp, u, visited, color)){
                return false;
            }
        }
        else if(color[u] == color[v]){
            return false;
        }
    }
    return true;
}
void solve(bool& ans){
    int n, interaction;
    cin >> n >> interaction;
    map<int, vector<int> > mp;
    int x, y;
    vector<bool> visited(n+1, false);
    vector<int> color(n+1, -1);
    for(int i = 0; i < interaction; i++){
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    visited[1] = true;
    for(int i = 1; i <= n; i++){
        if(i == 1 || !visited[i]){
            if(isBipartite(mp, i, visited, color) && ans == true){
                ans = true;
            }
            else{
                ans = false;
                return;
            }
        }
    }
}
int main(){
    int t;
    cin >> t;
    for(int testCase = 1; testCase <= t; testCase++){
        bool ans = true;
        solve(ans);
        cout << "Scenario #" << testCase << ":\n";
        if(ans){
            cout << "No suspicious bugs found!\n";
        }
        else{
            cout << "Suspicious bugs found!\n";
        }
    }
    return 0;
}
