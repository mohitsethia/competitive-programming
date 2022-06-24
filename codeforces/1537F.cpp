#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
using ll = long long;
bool isBirpartite(vector<vector<ll> >& graph,  ll n, vector<ll>& color){
    color[0] = 1;
    queue<ll> q;
    q.push(0);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(auto &v: graph[u]){
            if(u == v){
                continue;
            }
            if(color[v] == -1){
                color[v] = 1-color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        vector<ll> initial(n), target(n);
        vector<vector<ll> > graph(n+1);
        ll sumInitial = 0, sumTarget = 0;
        for(ll i = 0; i < n; i++){
            cin >> initial[i];
            sumInitial += initial[i];
        }
        for(ll i = 0; i < n; i++){
            cin >> target[i];
            sumTarget += target[i];
        }
        ll u, v;
        for(ll i = 0; i < m; i++){
            cin >> u >> v;
            --u, --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        if(abs(sumInitial)%2 != abs(sumTarget)%2){
            cout << "NO\n";
            continue;
        }
        vector<ll> color(n+1, -1);
        if(!isBirpartite(graph, n, color)){
            cout << "YES\n";
            continue;
        }
        ll white = 0, black = 0;
        for(ll i = 0; i < n; i++){
            if(color[i] == 0){
                white += initial[i] - target[i];
            }
            else{
                black += initial[i] - target[i];
            }
        }
        if(white == black){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
