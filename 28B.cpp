#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

const int N = 1e5+1;

vector<int> g[N];
set<int> s1, s2;
int a[N], b[N], vis[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++){
        int u = i;
        int v = i+b[i];
        if(v >= 1 && v <= n){
            g[u].push_back(v);
            g[v].push_back(u);
        }
        v = i-b[i];
        if(v >= 1 && v <= n){
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    std::function<void(int)> dfs = [&](int k){
        if(vis[k]) return;
        s1.insert(k);
        s2.insert(a[k]);
        vis[k]++;
        for(auto it: g[k]){
            dfs(it);
        }
    };

    for(int i = 1; i <= n; i++){
        if(vis[i]) continue;
        s1.clear();
        s2.clear();
        dfs(i);
        if(s1 != s2){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
