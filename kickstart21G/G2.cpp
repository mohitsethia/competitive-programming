#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<map>
#include<unordered_map>
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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define sz(x)           ((int)x.size())
#define all(x)          x.begin(), x.end()

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}
struct chash {
    int operator()(int x) const { return hash_f(x); }
};
#define gp              gp_hash_table<int, int, chash>


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.ff>>a.ss;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.ff<<" "<<a.ss;return out;}


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

struct cord{
    int x1, y1, x2, y2;
};

int manhattan(int x1, int y1, int x2, int y2){
    return abs(x1-x2)+abs(y1-y2);
}

int findDistance(vector<cord> &a, int x, int y){
    int sum = 0;
    for(int i = 0; i < sz(a); i++){
        if(a[i].x1 <= x && a[i].y1 <= y && a[i].x2 >= x && a[i].y2 >= y) continue;
        int p = LLONG_MAX;
        for(int j = min(a[i].x1, a[i].x2); j <= max(a[i].x1, a[i].x2); j++){
            p = min(p, manhattan(j, a[i].y1, x, y));
            p = min(p, manhattan(j, a[i].y2, x, y));
        }
        for(int j = min(a[i].y1, a[i].y2); j <= max(a[i].y1, a[i].y2); j++){
            p = min(p, manhattan(a[i].x1, j, x, y));
            p = min(p, manhattan(a[i].x2, j, x, y));
        }
        sum += p;
    }
    return sum;
}

void solve(){
    int k;
    cin >> k;
    vector<cord> a(k);
    int mn = inf;
    int mx = -inf;
    for(int i = 0; i < k; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        mn = min({mn, a[i].x1, a[i].x2, a[i].y1, a[i].y2});
        mx = max({mx, a[i].x1, a[i].x2, a[i].y1, a[i].y2});
    }
    int res = LLONG_MAX;
    int point1 = 0, point2 = 0;
    for(int i = mn; i <= mx; i++){
        for(int j = mn; j <= mx; j++){
            int dis = findDistance(a, i, j);
            if(res > dis){
                point1 = i;
                point2 = j;
                res = dis;
            }
            else if(res == dis){
                if(point2 == j) point1 = min(point1, i);
                else if(point1 == i) point2 = min(point2, j);
            }
        }
    }
    cout << point1 << " " << point2;
}

int32_t main(){
    FIO;
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        cout << "\n";
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
