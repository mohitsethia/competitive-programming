#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<array>
using namespace std;
int n, m;
map<char, array<int, 2> > d;
vector<string> c, s;
vector<vector<bool> > vis1, vis2;
vector<array<int, 2> > cyc;
vector<int> a;
vector<vector<vector<array<int, 2> > > > adj;
array<int, 2> nxt(array<int, 2> u){
    return {u[0] + d[s[u[0]][u[1]]][0], u[1] + d[s[u[0]][u[1]]][1]};
}
void dfs1(array<int, 2> u){
    if(vis1[u[0]][u[1]]){
        cyc.push_back(u);
        return;
    }
    vis1[u[0]][u[1]] = 1;
    dfs1(nxt(u));
    if(cyc.back() == nxt(u) && cyc[0] != u){
        cyc.push_back(u);
    }
}

void dfs2(array<int, 2> u, int d = 0){
    vis2[u[0]][u[1]] = 1;
    if((c[u[0]][u[1]]&1) ^ 1){
        ++a[d%(int)cyc.size()];
    }
    for(array<int, 2> v: adj[u[0]][u[1]]){
        if(!vis2[v[0]][v[1]]){
            dfs2(v, d+1);
        }
    }
}

void solve(){
    cin >> n >> m;
    c = s = vector<string>(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    adj = vector<vector<vector<array<int, 2> > > >(n, vector<vector<array<int, 2> > >(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            array<int, 2> u = {i, j};
            array<int, 2> v = nxt(u);
            adj[v[0]][v[1]].push_back(u);
        }
    }
    vis1 = vis2 = vector<vector<bool> >(n, vector<bool>(m));
    int all = 0, black = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis2[i][j]){
                continue;
            }
            cyc.clear();
            dfs1({i, j});
            all += cyc.size();
            a = vector<int>(cyc.size());
            dfs2(cyc[0]);
            for(int i = 0; i < (int)a.size(); i++){
                black += a[i]>0;
            }
        }
    }
    cout << all << " " << black << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    d['U'] = {-1, 0};
    d['D'] = {1, 0};
    d['R'] = {0, 1};
    d['L'] = {0, -1};
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
