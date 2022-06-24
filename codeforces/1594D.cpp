#include<iostream>
#include<algorithm>

using namespace std;

class DSU{
    public:
    vector<int> par, sz, rk;
    DSU(int n){
        par.resize(2*n+1);
        sz.resize(2*n+1);
        rk.resize(2*n+1, 1);
        for(int i = 1; i <= n; i++){
            par[i] = i;
            par[i+n] = i+n;
            sz[i+n] = 1;
        }
    }
    int find(int i){
        if(par[i] == i) return i;
        return par[i] = find(par[i]);
    }
    void unite(int i, int j){
        i = find(i);
        j = find(j);
        if(i != j){
            if(rk[i] < rk[j]) swap(i, j);
            par[j] = i;
            rk[i] += rk[j];
            sz[i] += sz[j];
        }
    }
};

void solve(){
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while(q--){
        int x, y;
        string s;
        cin >> x >> y >> s;
        if(s[0] == 'c'){
            dsu.unite(x, y);
            dsu.unite(x+n, y+n);
        }
        else{
            dsu.unite(x, y+n);
            dsu.unite(x+n, y);
        }
    }
    for(int i = 1; i <= n; i++){
        if(dsu.find(i) == dsu.find(i+n)){
            cout << "-1\n";
            return;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(dsu.find(i) == i){
            ans += max(dsu.sz[dsu.find(i)], dsu.sz[dsu.find(i+n)]);
        }
    }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
