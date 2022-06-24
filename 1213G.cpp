#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int N = 2e5+1;
int rt[N], sz[N];

void init(){
    for(int i = 0; i < N; i++){
        rt[i] = i;
        sz[i] = 1;
    }
}

int root(int x){
    while(x != rt[x]){
        rt[x] = rt[rt[x]];
        x = rt[x];
    }
    return x;
}

bool merge(int x, int y){
    int r1 = root(x);
    int r2 = root(y);
    if(r1 == r2) return false;
    if(sz[r1] < sz[r2]) swap(r1, r2);
    sz[r1] += sz[r2];
    rt[r2] = r1;
    return true;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > edges(n-1);
    for(int i = 0; i < n-1; i++){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
    }
    sort(edges.begin(), edges.end());
    vector<pair<int, int> > queries(m);
    vector<int> ans(m);
    for(int i = 0; i < m; i++){
        cin >> queries[i].first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());
    int pos = 0;
    int res = 0;
    for(int i = 0; i < m; i++){
        while(pos < n-1 && edges[pos].first <= queries[i].first){
            int u = edges[pos].second.first;
            int v = edges[pos].second.second;
            int x = root(u);
            int y = root(v);
            int sx = sz[x], sy = sz[y];
            if(merge(x, y)){
                res += sx*sy;
            }
            pos++;
        }
        ans[queries[i].second] = res;
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
