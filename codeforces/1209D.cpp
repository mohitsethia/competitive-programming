#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

class DSU{
    public:
    vector<int> par, sz;
    DSU(int n):par(n+1), sz(n+1){
        for(int i = 1; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

int32_t main(){
    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    int ans = k;
    while(k--){
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    for(int i = 1; i <= n; i++){
        if(dsu.find(i) == i){
            ans -= dsu.sz[i]-1;
        }
    }
    cout << ans << "\n";
    return 0;
}
