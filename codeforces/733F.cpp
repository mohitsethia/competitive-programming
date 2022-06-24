#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const int N = 2e5+5;
struct edge{
    ll u, v, w;
};
bool comp(edge a, edge b){
    return a.w < b.w;
}
edge edges[N];
ll n, m;
vector<ll> par(N);
ll find(ll x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);
}
void merge(ll x, ll y){
    ll p = find(x), q = find(y);
    par[p] = q;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i <= n; i++){
        par[i] = i;
    }
    for(ll i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    ll s = 0ll;
    ll sum = 0;
    vector<pair<ll, ll> > cool;
    sort(edges, edges+m, comp);
    for(ll i = 0; i < m; i++){
        ll x = edges[i].u, y = edges[i].v;
        if(find(x) != find(y)){
            merge(x, y);
            cool.emplace_back(x, y);
            sum += edges[i].w;
        }
    }
    sum -= s;
    cout << sum << endl;
    for(auto it: cool){
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}
