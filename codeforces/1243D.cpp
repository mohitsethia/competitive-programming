#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

#define int long long

set<int> unvisited;
set<vector<int> > edges;

int32_t main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
        edges.insert({v, u});
    }
    int ans = -1;
    for(int i = 1; i <= n; i++)
        unvisited.insert(i);

    std::function<void(int)> dfs = [&](int i){
        unvisited.erase(i);
        auto it = unvisited.begin();
        while(it != unvisited.end()){
            int j = *it;
            if(!edges.count({i, j})) dfs(j);
            it = unvisited.upper_bound(j);
        }
    };

    for(int i = 1; i <= n; i++){
        if(unvisited.count(i)){
            dfs(i);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
