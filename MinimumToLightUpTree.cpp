#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5+1;
int n;
vector<int> g[N];
int dp[N][2];
void dfs(int src, int p){
    for(auto child: g[src]){
        if(child != p) dfs(child, src);
    }
    for(auto child: g[src]){
        if(child != p){
            dp[src][0] += dp[child][1];
            dp[src][1] += min(dp[child][0], dp[child][1]);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    dp[n][0] = 0;
    dp[n][1] = 1;
    dfs(1, -1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
