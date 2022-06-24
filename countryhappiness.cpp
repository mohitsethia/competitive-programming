#include<iostream>
#include<map>
using namespace std;
#define int long long
class graph{
    map<int, list<int> > mp;
    
    void addEdge(int x, int y){
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    void dfs(int *visited, int src){
        
    }
};
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> h[i];
        }
    }
    return 0;
}
