#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

const int N = 1e5+3;

vector<int> pos(N, -1);
vector<int> g[N], col[N], s;
vector<int> cycle;

bool dfs(int src){
    pos[src] = s.size();
    col[pos[src]%2].push_back(src);
    s.push_back(src);
    int l = -1;
    for(int dest: g[src]){
        if(pos[dest] != -1 && pos[src]-pos[dest] > 1) l = max(l, pos[dest]);
    }
    if(l != -1){
        for(int i = l; i <= pos[src]; i++){
            cycle.push_back(s[i]);
        }
        return true;
    }
    for(int dest: g[src]){
        if(pos[dest] == -1){
            if(dfs(dest)) return true;
        }
    }
    s.pop_back();
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    while(m--){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    if(cycle.size() > 0 && cycle.size() <= k){
        cout << "2\n";
        cout << cycle.size() << "\n";
        for(int i: cycle){
            cout << i << " ";
        }
    }
    else{
        if((int)cycle.size() == 0){
            if(col[0].size() < col[1].size()) swap(col[0], col[1]);
            cout << "1\n";
            for(int i = 0; i < (k+1)/2; i++){
                cout << col[0][i] << " ";
            }
        }
        else{
            cout << "1\n";
            for(int i = 0; i < (k+1)/2; i++){
                cout << cycle[2*i] << " ";
            }
        }
    }
    cout << "\n";
    return 0;
}
