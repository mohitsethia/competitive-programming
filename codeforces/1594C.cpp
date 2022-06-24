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
#define all(x)          x.begin(), x.end()
#define sz(x)           ((int)x.size())

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

const int N = 10000000;
vector<int> lp(N+1);
vector<int> pr;

void sieve(){
    lp[1] = 1;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

void solve(){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    int difference = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != c){
            difference++;
            break;
        }
    }
    if(!difference){
        cout << "0\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        bool ok = true;
        for(int j = i; j <= n; j += i){
            if(s[j-1] != c){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << "1\n";
            cout << i << "\n";
            return;
        }
    }
    cout << "2\n" << n << " " << n-1 << "\n";
}

int32_t main(){
    FIO;
    // sieve();
    w(t){
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
