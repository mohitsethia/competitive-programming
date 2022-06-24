#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<unordered_map>
using namespace std;
class graph{
    unordered_map<int, vector<pair<int, int> > > mp;
    int n;
public:
    void init(int n){
        this->n = n;
    }
    void addEdge(int u, int v, int time){
        mp[u].push_back({v, time});
        mp[v].push_back({u, time});
    }
    int dijkstra(int start, int end){
        set<pair<int, int> > s;
        unordered_map<int, int> timing;
        for(int i = 1; i <= n; i++){
            timing[i] = INT_MAX;
        }
        s.insert({0, start});
        timing[start] = 0;
        while(!s.empty()){
            auto p = *(s.begin());
            int node = p.second;
            int timeToReachNode = p.first;
            s.erase(s.begin());
            for(auto eachNode: mp[node]){
                if(timeToReachNode + eachNode.second < timing[eachNode.first]){
                    auto f = s.find({timing[eachNode.first], eachNode.first});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    timing[eachNode.first] = timeToReachNode+eachNode.second;
                    s.insert({timing[eachNode.first], eachNode.first});
                }
            }
        }
        return (timing[end] == INT_MAX ? -1 : timing[end]);
    }
};
void solve(){
    int n, m, start, end, x, y, time;
    cin >> n >> m >> start >> end;
    graph g;
    g.init(n);
    while(m--){
        cin >> x >> y >> time;
        g.addEdge(x, y, time);
    }
    if(start == end){
        cout << "0\n";
        return;
    }
    int ans = g.dijkstra(start, end);
    if(ans == -1){
        cout << "NONE\n";
    }
    else{
        cout << ans << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
