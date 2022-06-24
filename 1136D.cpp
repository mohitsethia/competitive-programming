#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1], p(n+1), good(n+1);
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        if(v == p[n]){
            good[u] = true;
        }
    }
    set<int> dk;
    int ans = 0;
    for(int i = n-1; i >= 1; i--){
        if(!good[p[i]]) dk.insert(p[i]);
        else{
            int ctr = 0;
            for(auto &v: g[p[i]]){
                if(dk.count(v)) ++ctr;
            }
            if(ctr == (int)dk.size()) ans++;
            else dk.insert(p[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
