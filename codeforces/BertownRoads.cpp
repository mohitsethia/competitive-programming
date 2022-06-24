#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<climits>
#include<cstring>

using namespace std;
const int N = 1e5+1;
int n;
bool hasBridge = false;
map<int, set<int> > mp;
vector<pair<int, int> > edgeList;
void dfs(int src, int par, vector<int> &disc, vector<int> &low, vector<bool> &vis){
    if(hasBridge) return;
    static int timer = 0;
    vis[src] = true;
    disc[src] = low[src] = timer++;
    for(auto it: mp[src]){
        if(it == par) continue;
        if(vis[it]){
            low[src] = min(low[src], disc[it]);
            if(disc[it] > disc[src]){
                edgeList.emplace_back(make_pair(it, src));
            }
        }
        else{
            dfs(it, src, disc, low, vis);
            low[src] = min(low[src], low[it]);
            if(low[it] > disc[src]){
                hasBridge = true;
                return;
            }
            edgeList.emplace_back(make_pair(src, it));
        }
    }
}
/*
map<pair<int, int>, bool> s;
void print(int u, int from, vector<bool> &vis){
    vis[u] = true;
    for(auto v: mp[u]){
        if(v == from) continue;
        else if(!vis[v]){
            vis[v] = true;
            s[{u, v}] = s[{v, u}] = true;
            cout << u << " " << v << "\n";
            print(v, u, vis);
        }
        else{
            if(s[{u, v}] == false){
                s[{u, v}] = true;
                s[{v, u}] = true;
                cout << u << " " << v << "\n";
            }
        }
    }
}
*/
void tarjan(){
    vector<int> low(n+1), disc(n+1);
    vector<bool> vis(n+1, false);
    dfs(1, 0, disc, low, vis);
    if(hasBridge){
        cout << 0;
        return;
    }
    // vis = vector<bool>(n+1, false);
//    print(1, 1, vis);
    for(auto it: edgeList){
        cout << it.first << " " << it.second << "\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> n >> m;
    if(m == n-1){
        cout << 0;
        return 0;
    }
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    tarjan();
    return 0;
}
