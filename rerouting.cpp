#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<list>
#include<queue>
using namespace std;
class graph{
public:
    vector<int> par;
    int total_comp;
    void init(int n, int *a){
        par.resize(n+1);
        for(int i = 1; i <= n; i++){
            par[a[i]] = a[i];
        }
        total_comp = n;
    }
    int get_superparent(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = get_superparent(par[x]);
    }
    void unite(int x, int y){
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        if(super_parent_x != super_parent_y){
            par[super_parent_x] = super_parent_y;
            total_comp--;
        }
    }
    int comp(){
        return total_comp;
    }
};
int main(){
    int n;
    cin >> n;
    int a[n+1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    graph g;
    g.init(n, a);
    for(int i = 1; i <= n; i++){
        g.unite(a[i], a[a[i]]);
    }
    int ans = g.comp();
    if(ans <= 1){
        cout << 0 << endl;
    }
    else{
        cout << ans - 1 << endl;
    }
    return 0;
}
