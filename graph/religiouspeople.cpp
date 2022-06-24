#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<climits>
#include<cmath>
#include<list>
using namespace std;
#define int long long
class graph{
    unordered_map<int, list<int> > mp;
    public:
        void addEdge(int x, int y){
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        void components(int n, int m, int a, int b){
            int sum = 0;
            vector<int> edges;
            vector<bool> visited(n+1, false);
            int count = 0, ct = 0;
            if(a <= b){
                sum = a*n;
                cout << sum << endl;
                return;
            }
            else{
                for(int i = 1; i <= n; i++){
                    if(!visited[i]){    
                        ct = 0;
                        DFSUtil(i, visited, ct);
                        count += 1;
                        edges.push_back(ct - 1);
                    }
                }
            }
            int ans = count * a;
            for(auto i:edges){
                ans += (i*b);
            }
            cout << ans << endl;
            return;
        }
        void DFSUtil(int node, vector<bool> &visited, int &ct){
            visited[node] = true;
            ct += 1;
            for(auto i:mp[node]){
                if(!visited[i]){
                    DFSUtil(i, visited, ct);
                }
            }
        }
};
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        graph g;
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            g.addEdge(x, y);
        }
        //bool visited[100005] = {false};
        g.components(n, m, a, b);
    }
    return 0;
}
