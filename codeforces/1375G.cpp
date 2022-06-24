#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 2e5 + 2;
vector<int> adj[N];
int s[2];

void dfs(int u = 0, int p = -1, int c = 0){
    ++s[c];
    for(int v: adj[u]){
        if(v^p){
            dfs(v, u, c^1);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout << min(s[0], s[1])-1 << "\n";
    return 0;
}
