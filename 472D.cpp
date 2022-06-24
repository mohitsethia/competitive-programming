#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int N = 2001;
const int H = 19;
int par[N][H+1], lvl[N];
ll d[N][N];
ll sum[N] = {0};
vector<int> tree[N];
struct node{
    int u, p, w;
    node(){}
    node(int u, int p, int w): u(u), p(p), w(w){}
    bool operator < (const node &op) const {
        return w > op.w;
    }
};
priority_queue<node> pq;
vector<bool> vis(N);
int n;
void dijkstra(){
    pq.push(node(1, 0, 0));
    while(!pq.empty()){
        int u = pq.top().u;
        int p = pq.top().p;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        tree[p].push_back(u);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                pq.push(node(i, u, d[u][i]));
            }
        }
    }
}
void dfs(int z, int p){
    par[z][0] = p;
    lvl[z] = lvl[p]+1;
    sum[z] = sum[p]+d[p][z];
    for(int i = 1; i <= H; i++){
        par[z][i] = par[par[z][i-1]][i-1];
    }
    for(auto it: tree[z]){
        if(it != p){
            dfs(it, z);
        }
    }
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i = H; i >= 0; i--){
        if(lvl[x]-(1 << i) >= lvl[y]){
            x = par[x][i];
        }
    }
    if(x == y) return x;
    for(int i = H; i >= 0; i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i], y = par[y][i];
        }
    }
    return par[x][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> d[i][j];
            if((i != j && d[i][j] == 0) || (i == j && d[i][j] != 0)){
                cout << "NO\n";
                return 0;
            }
        }
    }
    dijkstra();
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int dep = lca(i, j);
            int dist = sum[i] + sum[j] - 2*sum[dep];
            if(d[i][j] != dist){
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
