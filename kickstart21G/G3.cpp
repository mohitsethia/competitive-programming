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

int findSubarray(vi &a, int k, int n, int target){
    int curr_sum = a[k];
    int i, j = k;
    int res = INT_MAX;
    for(i = k+1; i <= n; i++){
        while(curr_sum > target && j < i-1){
            curr_sum -= a[j];
            j++;
        }
        if(curr_sum == target){
            res = min(res, i-j+1);
        }
        if(i < n) curr_sum += a[i];
    }
    if(res == INT_MAX) res = -1;
    return res;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    vi pref(n);
    bool found = false;
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        total_sum += a[i];
        if(a[i] == k) found = true;
        pref[i] = (i == 0 ? a[i] : (pref[i-1] + a[i]));
    }
    if(found){
        cout << 1;
        return;
    }
    if(total_sum < k){
        cout << -1;
        return;
    }
    int ans = INT_MAX;
    for(int j = 0; j < n; j++){
        for(int i = j; i >= 0; i--){
            // debug(pref[j]);
            int sum = j == 0 ? pref[j] : (pref[j] - (i == 0 ? 0 : pref[i-1]));
            // debug(sum);
            int target = k - sum;
            if(target < 0) break;
            if(target == 0){
                ans = min(ans, j-i+1);
                continue;
            }
            int res = findSubarray(a, j+1, n, target);
            if(res == -1) continue;
            ans = min(j-i + res, ans);
        }
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;
}

int32_t main(){
    FIO;
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case #" << tc << ": ";
        solve();
        if(tc < t) cout << "\n";
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
