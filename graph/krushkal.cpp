#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class dsu{
    vector<int> p;
    public:
        void init(int n){
            p.clear();
            p.resize(n);
            iota(p.begin(), p.end(), 0);
        }
        int get(int x){
            return (x == p[x] ? x : (p[x] = get(p[x])));
        }
        void unite(int x, int y){
            x = get(x);
            y = get(y);
            if(x != y){
                p[x] = y;
            }
        }
};
void solve(){
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > edges(m);
    for(i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = (make_pair(w, make_pair(x, y)));
    }
    sort(edges.begin(), edges.end());
    dsu g;
    g.init(n+1);
    for(i = 0; i < m; i++){
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        int w = edges[i].first;
//        cout << w << " " << x << " " << y << endl;
        if(g.get(x) != g.get(y)){
            //can take this edge
            g.unite(x, y);
            cout << w << " " << x << " " << y << endl; 
            //include all edges which doesn't result in a cycle
            ans += w;
        }
    }
    cout << ans;
}
int main(){
    solve();
    return 0;
}
