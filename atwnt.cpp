#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class graph{
    int n;
    map<int, vector<int> > mp;
    public:
        void init(int x){
            n = x;
        }
        void addEdge(int u, int v){
            mp[u].push_back(v);
        }
        void dfs(int v, int w, int& ans, vector<bool>& visited){
            //cout << "w: " << w << " mp[" << v << "].size(): " << mp[v].size() << endl;
            if(mp[v].size() == 0){
                //cout << "returning here only " << ans << endl;
                return;
            }
            int sz = mp[v].size();
            if(w%sz == 0){
                w /= mp[v].size();
                for(auto it: mp[v]){
                    if(!visited[it]){
                        visited[it] = true;
                        dfs(it, w, ans, visited);
                    }
                }
            }
            else{
                ans += w;
                //cout << ans << endl;
                return;
            }
            //cout << ans << endl;
            return;
        }
};
void solve(){
    int n;
    scanf("%d", &n);
    graph g;
    g.init(n);
    for(int i = 2; i <= n; i++){
        int x;
        scanf("%d", &x);
        g.addEdge(x, i);
    }
    int q;
    scanf("%d", &q);
    while(q--){
        vector<bool> visited(n, false);
        int ans = 0;
        int v, w;
        scanf("%d%d", &v, &w);
        g.dfs(v, w, ans, visited);
        printf("%d\n", ans);
    }
}
int main(){
    solve();
    return 0;
}

