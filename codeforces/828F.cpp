#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
using ll = long long;
const int N = 2e5+5;
struct node{
    ll u, v, w, i;
};
node tree[N];
vector<int> par(N);
int n, m;
bool comp(node a, node b){
    return a.w < b.w;
}
int find(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);
}
void merge(int x, int y){
    int p = find(x), q = find(y);
    par[p] = q;
}
vector<int> res(N, -1);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        par[i] = i;
    }
    for(int j = 0; j < m; j++){
        cin >> tree[j].u >> tree[j].v >> tree[j].w;
        tree[j].i = j;
    }
    sort(tree, tree + m, comp);
    long long ans = 0;
    set<int> store;
    for(int i = 0; i < m; i++){
        int x = find(tree[i].u), y = find(tree[i].v);
        if(x != y){
            merge(x, y);
            ans = max(ans, tree[i].w);
            store.insert(tree[i].i);
        }
    }
    if(store.size() == m){
        for(int i = 1; i <= m; i++){
            cout << "-1 ";
        }
    }
    else{
        for(auto it: store){
            res[it] = ans;
        }
        for(int i = 0; i < m; i++){
            if(store.find(i) == store.end()){
                res[i] = ans-1;
            }
        }
        for(int i = 0; i < m; i++){
            cout << res[i] << " ";
        }
    }
    return 0;
}
