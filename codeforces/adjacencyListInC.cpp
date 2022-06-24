#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+1;

bool vis[N];
int eo[N], *ej[N];

void append(int i, int j){
    int o = eo[i]++;
    if(o >= 2 && (o&(o-1)) == 0){
        ej[i] = (int*) realloc(ej[i], (o << 1) * sizeof *ej[i]);
    }
    ej[i][o] = j;
}

void dfs(int u){
    vis[u] = true;
    cout << u+1 << " ";
    for(int o = eo[u]; o--; ){
        int j = ej[u][o];
        if(!vis[j]) dfs(j);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        eo[i] = 0;
        ej[i] = (int*) malloc(2* sizeof *ej[i]);
    }
    while(m--){
        int u, v;
        cin >> u >> v;
        u--, v--;
        append(u, v);
        append(v, u);
    }
    dfs(0);
    return 0;
}
