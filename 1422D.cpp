#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<cstring>

using namespace std;

#define int long long

const int N = 2e5+10;

vector<pair<int, int> > g[N];
int n, m, x[N], y[N], dis[N];

void dijkstra(){
    set <pair<int, int> > s;
    s.insert({0 , 0});
    memset(dis , 63, sizeof(dis));
    for(int i = 0; i < n; i++) cout << dis[i] << " ";
    cout << "\n";
    while(s.size()){
        pair<int, int> x = *s.begin();
        s.erase(s.begin());
        for(pair<int, int> y : g[x.second]){
            if(dis[y.first] > y.second + x.first){
                s.erase({dis[y.first] , y.first});
                dis[y.first] = y.second + x.first;
                s.insert({dis[y.first] , y.first});
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    int ans = abs(sx-fx) + abs(sy-fy);
    vector<pair<int, int> > v1, v2;
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i];
        g[0].push_back({i , min(abs(x[i] - sx) , abs(y[i] - sy))});
        g[i].push_back({m + 1 , abs(x[i] - fx) + abs(y[i] - fy)});
        v1.push_back({x[i] , i});
        v2.push_back({y[i] , i});
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    /*
       for(int i = 1; i < m; i++){
       int p = v1[i].second;
       int q = v1[i-1].second;
       g[p].push_back({q, x[p]-x[q]});
       g[q].push_back({p, x[p]-x[q]});
       p = v2[i].second;
       q = v2[i-1].second;
       g[p].push_back({q, y[p]-y[q]});
       g[q].push_back({p, y[p]-y[q]});
       }
     */
    for(int i = 1 ; i < m ; i++){
        int i1 = v1[i].second;
        int i2 = v1[i - 1].second;
        g[i1].push_back({i2 , x[i1] - x[i2]});
        g[i2].push_back({i1 , x[i1] - x[i2]});
    }
    for(int i = 1 ; i < m ; i++){
        int i1 = v2[i].second;
        int i2 = v2[i - 1].second;
        g[i1].push_back({i2 , y[i1] - y[i2]});
        g[i2].push_back({i1 , y[i1] - y[i2]});
    }
    dijkstra();
    ans = min(ans, dis[m+1]);
    cout << ans << "\n";
    return 0;
}
