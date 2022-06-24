//#ifndef LOCAL
//#pragma GCC optimize ("-Ofast")
//#pragma GCC optimize ("-unroll-loops")
//#endif
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<climits>
#include<queue>
#include<cstring>
using namespace std;
#define pii pair<int, int>
#define vi vector<int>
#define vpi vector<pii>
#define mi map<int, int>
#define mpi map<pii, int>
#define mk make_pair
#define pb push_back
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


const int MOD = 1e9 + 7;
const int N= 1e6 + 10;
vi adj[N];
bool vis[N];
int arr[N];
int low[N];
vpi po;
mpi mm;
vi ad[N];
int timer = 0;
void dfs(int src, int par = 0){
    vis[src] = true;
    arr[src] = timer++;
    low[src] = arr[src];
    for(int &to: adj[src]){
        if(to == par) continue;
        if(vis[to]){
            low[src] = min(low[src], arr[to]);
        }
        else{
            dfs(to, src);
            low[src] = min(low[src], low[to]);
            if(low[to] > arr[src]){
                if(mm[mk(to, src)] == 0 && mm[mk(src, to)] == 0){
                    mm[mk(to, src)]++;
                    mm[mk(src, to)]++;
                }
            }
        }
    }
}
int start = 0, ans = 0, cnt = 0;
void df(int u){
    cnt++;
    vis[u] = true;
    for(int &x: ad[u]){
        if(!vis[x]) df(x);
    }
}
mpi m2;
void dfs2(int src, int par){
    vis[src] = 1;
    for(int &to: adj[src]){
        if(to == par) continue;
        if(!vis[to])
            dfs2(to, src);
        debug(src, to);
        if(m2[mk(src, to)] == 0 && mm[mk(to, src)]){
            m2[mk(to, src)]++;
        }
        if(m2[mk(to, src)] == 0 && !mm[mk(to, src)]){
            m2[mk(src, to)]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
	    if (fopen("input.txt", "r"))
        {
            freopen ("input.txt" , "r" , stdin); freopen ("output.txt" , "w" , stdout);
        }
    #endif


    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        po.pb(mk(u, v));
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    for(pii &x: po){
        if(mm[x] > 0) continue;
        ad[x.first].pb(x.second);
        ad[x.second].pb(x.first);
    }
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= n; i++){
        cnt = 0;
        if(!vis[i]) df(i);
        if(cnt > ans){
            ans = cnt;
            start = i;
        }
    }
    cout << ans << "\n";
    memset(vis, false, sizeof vis);
    debug(start);
    for(int i = 1; i <= n; i++){
        debug(vis[i]);
    }
    dfs2(start, 0);
    for(pii &x: po){
        int p = x.first;
        int q = x.second;
        if(m2[x]) cout << p << " " << q << "\n";
        else cout << q << " " << p << "\n";
    }
    #ifndef ONLINE_JUDGE
	    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif

    return 0;
}

