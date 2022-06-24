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

vector<vi> findLDS(vector<int> const &nums)
{
    int n = nums.size();
 
    // base case
    if (n == 0) {
        return {};
    }
 
    // `LDS[i]` stores the longest decreasing subsequence of subarray
    // `nums[0…i]` that ends with `nums[i]`
    vector<vector<int>> LDS(n, vector<int>());
 
    // `LDS[0]` denotes longest decreasing subsequence ending at `nums[0]`
    LDS[0].push_back(nums[0]);
 
    // start from the second array element
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray `nums[0…i-1]`
        for (int j = 0; j < i; j++)
        {
            // find longest decreasing subsequence that ends with `nums[j]`
            // where `nums[j]` is more than the current element `nums[i]`
 
            if (nums[j] >= nums[i] && LDS[j].size() > LDS[i].size()) {
                LDS[i] = LDS[j];
            }
        }
 
        // include `nums[i]` in `LDS[i]`
        LDS[i].push_back(nums[i]);
    }
 
    // uncomment the following code to print contents of `LDS`
    /* for (int i = 0; i < n; i++)
    {
        cout << "LDS[" << i << "] — ";
        for (int j: LDS[i]) {
            cout << j << " ";
        }
        cout << endl;
    } */
 
    // `j` will contain an index of LDS
    sort(LDS.begin(), LDS.end(), [&](vector<int> &p, vector<int> &q){
        return p.size() > q.size();
    });
    for(int i = 1; i < (int)LDS.size(); i++){
        if(LDS[i].size() != LDS[i-1].size()){
            while((int)LDS.size() > i){
                LDS.pop_back();
            }
            break;
        }
    }
    return LDS;
}

vector<vi> findLIS(vector<int> const &arr)
{
    int n = arr.size();

    // base case
    if (n == 0) {
        return {};
    }

    // LIS[i] stores the longest increasing subsequence of subarray
    // `arr[0…i]` that ends with `arr[i]`
    vector<vector<int>> LIS(n, vector<int>{});

    // LIS[0] denotes the longest increasing subsequence ending at `arr[0]`
    LIS[0].push_back(arr[0]);

    // start from the second array element
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray `arr[0…i-1]`
        for (int j = 0; j < i; j++)
        {
            // find the longest increasing subsequence that ends with `arr[j]`
            // where `arr[j]` is less than the current element `arr[i]`

            if (arr[j] <= arr[i] && LIS[j].size() > LIS[i].size()) {
                LIS[i] = LIS[j];
            }
        }

        // include `arr[i]` in `LIS[i]`
        LIS[i].push_back(arr[i]);
    }

    // uncomment the following code to print contents of `LIS`
    /* for (int i = 0; i < n; i++)
    {
        cout << "LIS[" << i << "] — ";
        for (int j: LIS[i]) {
            cout << j << " ";
        }
        cout << endl;
    } */

    // `j` will store the index of LIS
    sort(LIS.begin(), LIS.end(), [&](vector<int> &p, vector<int> &q){
        return p.size() > q.size();
    });
    for(int i = 1; i < (int)LIS.size(); i++){
        if(LIS[i].size() != LIS[i-1].size()){
            while((int)LIS.size() > i){
                LIS.pop_back();
            }
            break;
        }
    }
    return LIS;
}

int findLCS(vector<int > &a, vector<int> &b){
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vi> LIS = findLIS(a);
    vector<vi> LDS = findLDS(a);
    int res = 0;
    for(int i = 0; i < (int)LIS.size(); i++){
        for(int j = 0; j < (int)LDS.size(); j++){
            res = max(res, findLCS(LIS[i], LDS[j]));
        }
    }
    cout << res << "\n";
}

int32_t main(){
    FIO;
    w(t){
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
