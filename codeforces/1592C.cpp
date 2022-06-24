#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 5;

vector<int> adj[N];
int a[N], p[N], tot;

int dfs(int u, int par){
    int cnt = 0;
    p[u] = a[u];
    for(int v: adj[u]){
        if(v == par) continue;
        cnt += dfs(v, u);
        p[u] ^= p[v];
    }
    if(u && p[u] == tot){
        ++cnt;
        p[u] = 0;
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        tot = 0;
        for(int i = 0; i < n; i++){
            p[i] = 0;
            adj[i].clear();
            cin >> a[i];
            tot ^= a[i];
        }
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(!tot){
            cout << "YES\n";
        }
        else if(k < 3){
            cout << "NO\n";
        }
        else{
            if(dfs(0, -1) >= 2){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    return 0;
}
