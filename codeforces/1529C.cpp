#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int N = 1e5+1;
vector<int> g[N];
ll dp[N][2];
void dfs(int src, int p, pair<ll, ll> s[]){
    for(auto it: g[src]){
        if(it == p) continue;
        dfs(it, src, s);
        dp[src][0] += max(dp[it][0]+abs(s[src].first-s[it].first), dp[it][1]+abs(s[src].first-s[it].second));
        dp[src][1] += max(dp[it][0]+abs(s[src].second-s[it].first), dp[it][1]+abs(s[src].second-s[it].second));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<ll, ll> s[n+1];
        for(int i = 1; i <= n; i++){
            cin >> s[i].first >> s[i].second;
            dp[i][0] = 0;
            dp[i][1] = 0;
            g[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(1, 0, s);
        cout << max(dp[1][0], dp[1][1]) << "\n";
    }
    return 0;
}
