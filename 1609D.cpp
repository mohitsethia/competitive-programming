#include<iostream>
#include<algorithm>
#include<set>


using namespace std;

multiset<int> s;

class DSU{
    public:
    vector<int> par;
    vector<int> sz;
    DSU(int n): par(n), sz(n, 1){
        for(int i = 1; i < n; i++){
            par[i] = i;
            s.insert(1);
        }
    }
    int find(int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        else if(sz[x] < sz[y]) swap(x, y);
        s.erase(s.find(sz[x]));
        s.erase(s.find(sz[y]));
        s.insert(sz[x] + sz[y]);
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    int extra = 0;
    DSU dsu(n+1);
    while(q--){
        int u, v;
        cin >> u >> v;
        if(!dsu.unite(u, v)){
            extra++;
        }
        int sum = 0, need = extra+1;
        for(auto i = s.rbegin(); i != s.rend() && need; i++, need--){
            sum += *i;
        }
        cout << sum-1 << "\n";
    }
    return 0;
}
