#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

const int N = 1e5 + 4;

set<int> s;
int h[N];
vector<int> leaf;
vector<int> gr[N];

void dfs(int u, int p){
    h[u] = h[p]+1;
    for(int v: gr[u]){
        if(v != p) dfs(v, u);
    }
    if((int)gr[u].size() == 1){
        leaf.push_back(u);
        s.insert(gr[u][0]);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(0, 0);
    bool odd = 0;
    bool even = 0;
    for(int l: leaf){
        if(h[l]&1){
            odd = true;
        }
        else{
            even = true;
        }
        if(odd && even) break;
    }
    if(odd && even) cout << "3 ";
    else cout << "1 ";
    cout << (n-1 - (int)leaf.size() + (int)s.size()) << "\n";
    return 0;
}
