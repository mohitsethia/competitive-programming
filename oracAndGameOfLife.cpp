#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = long long;
const ll maxx = 1e3 + 2;
ll n, m;
vector<vector<ll> > vis(maxx, vector<ll>(maxx));
vector<vector<ll> > a(maxx, vector<ll>(maxx));
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(){
    queue<pair<ll, ll> > q;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            for(ll k = 0; k < 4; k++){
                ll x = i + dx[k];
                ll y = j + dy[k];
                if(x < 1 || x > n || y < 1 || y > m) continue;
                if(a[x][y] == a[i][j]){
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
    }
    while(!q.empty()){
        pair<ll, ll> temp = q.front();
        q.pop();
        for(ll i = 0; i < 4; i++){
            ll x = temp.first + dx[i];
            ll y = temp.second + dy[i];
            if(x < 1 || x > n || y < 1 || y > m || vis[x][y]) continue;
            if(a[x][y] == (!a[temp.first][temp.second])){
                vis[x][y] = vis[temp.first][temp.second]+1;
                q.push({x, y});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll q;
    cin >> n >> m >> q;
    char c;
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= m; j++){
            cin >> c;
            a[i][j] = c-'0';
        }
    }
    bfs();
    ll x, y, t;
    while(q--){
        cin >> x >> y >> t;
        if(vis[x][y] > t || vis[x][y] == 0){
            cout << a[x][y] << "\n";
        }
        else{
            t -= vis[x][y];
            cout << (a[x][y]^((t+1)%2)) << "\n";
        }
    }
    return 0;
}
