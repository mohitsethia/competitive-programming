#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<iomanip>
#include<numeric>
#include<climits>
#include<cmath>
#include<cstring>
#include<chrono>
#include<random>
#include<bitset>
#include<stack>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)		substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x) 		cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}

void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int N = 1e5+2;
const int H = 20;
int n, q;
int par[N][H], lvl[N] = {0};
vi tree[N];
void dfs(int z, int p){
    par[z][0] = p;
    lvl[z] = lvl[p]+1;
    for(int i = 1; i < H; i++){
        par[z][i] = par[par[z][i-1]][i-1];
    }
    for(auto it: tree[z]){
        if(it == p) continue;
        dfs(it, z);
    }
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i = H-1; i >= 0; i--){
        if(lvl[x] - (1 << i) >= lvl[y]){
            x = par[x][i];
        }
    }
    if(x == y) return x;
    for(int i = H-1; i >= 0; i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i], y = par[y][i];
        }
    }
    return par[x][0];
}
int32_t main(){
    FIO;
    cin >> n >> q;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    dfs(1, 0);
    while(q--){
        cin >> u >> v;
        int d = lvl[u]+lvl[v] - 2*lvl[lca(u, v)];
        if(d%2){
            cout << "Road\n";
        }
        else{
            cout << "Town\n";
        }
    }
    return 0;
}
