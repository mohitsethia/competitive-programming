#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1005;

bool vis[N][N];
vector<pair<int, int>> adj[N][N];

int s = 0, n, m;

bool ok(int i, int j) {
    return (min(i, j) >= 0 && i < n && j < m);
}

void dfs(int i, int j) {
    ++s;
    vis[i][j] = true;
    for(auto a: adj[i][j]) {
        int x = a.first, y = a.second;
        if(!vis[x][y]) {
            dfs(x, y);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int num;
            cin >> num;
            if(!(num & (1 << 0))) {
                if(ok(i, j-1)) adj[i][j].push_back({i, j-1});
            }
            if(!(num & (1 << 1))) {
                if(ok(i+1, j)) adj[i][j].push_back({i+1, j});
            }
            if(!(num & (1 << 2))) {
                if(ok(i, j+1)) adj[i][j].push_back({i, j+1});
            }
            if(!(num & (1 << 3))) {
                if(ok(i-1, j)) adj[i][j].push_back({i-1, j});
            }
        }
    }
    vector<int> v;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                s = 0;
                dfs(i, j);
                v.push_back(s);
            }
        }
    }
    sort(v.rbegin(), v.rend());
    for(int x: v) {
        cout << x << " ";
    }
    return 0;
}
