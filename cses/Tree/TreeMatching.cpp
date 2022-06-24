#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2e5+1;
int n;
vector<int> g[N];
int dp[N][2];
void dfs(int z, int p){
    vector<int> pref;
    bool leaf = true;
    dp[z][0] = 0, dp[z][1] = 0;
    for(auto it: g[z]){
        if(it == p) continue;
        leaf = false;
        dfs(it, z);
    }
    if(leaf) return;
    for(auto child: g[z]){
        if(child == p) continue;
        pref.emplace_back(max(dp[child][0], dp[child][1]));
    }
    for(int i = 1; i < (int)pref.size(); i++){
        pref[i] += pref[i-1];
    }
    dp[z][0] = pref[(int)pref.size()-1];
    int i = 0;
    for(auto child: g[z]){
        if(child == p) continue;
        int leftChildren = 0;
        if(i == 0){
            leftChildren = 0;
        }
        else{
            leftChildren = pref[i-1];
        }
        int rightChildren = 0;
        if(i == (int)pref.size()-1){
            rightChildren = 0;
        }
        else{
            rightChildren = pref[(int)pref.size()-1] - pref[i];
        }
        dp[z][1] = max(dp[z][1], 1+leftChildren+rightChildren+dp[child][0]);
        i++;
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
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    return 0;
}
