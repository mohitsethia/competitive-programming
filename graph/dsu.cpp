#include<iostream>
#include<vector> 
using namespace std;
class dsu{
public:
    vector<int> par, sz;
    int total_comp;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
        for(int i = 0; i < n; i++){
            sz[i] = 1;
        }
        total_comp = n;
    }
    int get_superparent(int x){
        if(x == par[x]){
            return x;
        }
        else{
            return par[x] = get_superparent(par[x]);
        }
    }
    void unite(int x, int y){
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        if(super_parent_x != super_parent_y){
            par[super_parent_x] = super_parent_y;
            sz[super_parent_y] += sz[super_parent_x];
            sz[super_parent_x] = 0;
            total_comp--;
        }
    }
};
void solve(){
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    dsu g;
    g.init(n);
    bool cycle = 0;
    for(i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        if(g.get_superparent(x) != g.get_superparent(y)){
            g.unite(x, y);
        }
        else{
            cycle = 1;
        }
    }
    if(cycle){
        cout << "Cycle in the graph" << endl;
    }
    else{
        cout << "No Cycle" << endl;
    }
//    g.init(n);
//    g.unite(0, 1);
//    g.unite(2, 3);
//    g.unite(0, 4);
//    for(i = 0; i < n; i++){
//        cout << i << "->" <<  g.get_superparent(i) << endl;
//    }
//    for(i = 0; i < n; i++){
//        int super_parent_i = g.get_superparent(i);
//        ans += (n - g.sz[super_parent_i]);
//    }
//    cout << ans/2;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
