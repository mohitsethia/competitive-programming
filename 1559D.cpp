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
#include<unordered_map>

using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define eb              emplace_back
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

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(const char *t) {cerr << '\"' << t << '\"';}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
void _print(bool t) {cerr << (t ? "true" : "false");}
void _print(float t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "["<< #x << "] = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

class dsu{
public:
    vector<int> par, sz;
    int total_comp;
    void init(int n){
        par.resize(n+1);
        sz.resize(n+1);
        for(int i = 1; i <= n; i++){
            par[i] = i;
        }
        for(int i = 1; i <= n; i++){
            sz[i] = 1;
        }
        total_comp = n;
    }
    int get_superparent(int x){
        if(x == par[x]){
            return x;
        }
        else{
            return par[x] = get_superparent(par[x]);
        }
    }
    void unite(int x, int y){
        int super_parent_x = get_superparent(x);
        int super_parent_y = get_superparent(y);
        if(super_parent_x < super_parent_y){
            swap(super_parent_x, super_parent_y);
        }
            par[super_parent_x] = super_parent_y;
            sz[super_parent_y] += sz[super_parent_x];
            sz[super_parent_x] = 0;
            total_comp--;
    }
};

void solve(){
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    dsu mocha;
    dsu diana;
    mocha.init(n);
    diana.init(n);
    int u, v;
    for(int i = 0; i < m1; i++){
        cin >> u >> v;
        mocha.unite(u, v);
    }
    for(int i = 0; i < m2; i++){
        cin >> u >> v;
        diana.unite(u, v);
    }
    vector<pii> ans;
    vi v1, v2;
    for(int i = 1; i <= 1; i++){
        for(int j = i+1; j <= n; j++){
            if(mocha.get_superparent(i) != mocha.get_superparent(j) && diana.get_superparent(i) != diana.get_superparent(j)){
                ans.push_back(mp(i, j));
                mocha.unite(i, j);
                diana.unite(i, j);
            }
            if(mocha.get_superparent(j) != 1) v1.pb(j);
            if(diana.get_superparent(j) != 1) v2.pb(j);
        }
    }
    while(!v1.empty() && !v2.empty()){
        if(mocha.get_superparent(v1.back()) == 1 && diana.get_superparent(v1.back()) == 1){
            v1.pop_back();
            continue;
        }
        if(mocha.get_superparent(v2.back()) == 1 && diana.get_superparent(v2.back()) == 1){
            v2.pop_back();
            continue;
        }
        ans.pb(mp(v1.back(), v2.back()));
        mocha.unite(v1.back(), v2.back());
        diana.unite(v1.back(), v2.back());
        continue;
    }
    cout << ans.size() << "\n";
    for(auto it: ans){
        cout << it.first << " " << it.second << "\n";
    }
}

int32_t main(){
    FIO;
        solve();
    return 0;
}
