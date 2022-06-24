#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 5e4 + 2;
int ans[N];
vector<int> g[N];

int main(){
    int n, r1, r2;
    cin >> n >> r1 >> r2;
    for(int i = 1; i <= n; i++){
        if(i == r1) continue;
        int x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    std::function<void(int, int)> dfs = [&](int u, int p){
        ans[u] = p;
        for(auto it: g[u]){
            if(it == p) continue;
            dfs(it, u);
        }
    };
    dfs(r2, r2);
    for(int i = 1; i <= n; i++){
        if(i == r2) continue;
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
