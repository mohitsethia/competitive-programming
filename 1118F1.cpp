#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int N = 3e5+1;
int red, blue;
int ans;
int a[N];
vector<int> g[N];

pair<int, int> dfs(int u, int p = -1){
    int r = (a[u] == 1), b = (a[u] == 2);
    for(auto it: g[u]){
        if(it == p) continue;
        auto temp = dfs(it, u);
        ans += (temp.first == red && temp.second == 0);
        ans += (temp.first == 0 && temp.second == blue);
        r += temp.first;
        b += temp.second;
    }
    return {r, b};
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    red = 0, blue = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        red += (a[i] == 1);
        blue += (a[i] == 2);
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(0);
    cout << ans << "\n";
    return 0;
}
