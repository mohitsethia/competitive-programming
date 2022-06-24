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

void solve(){
    int n;
    cin >> n;
    set<int> a;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.insert(x);
        sum += x;
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        auto it = a.lower_bound(l);
        if(it == a.end()){
            int temp = *a.rbegin();
            int need = l-temp;
            int def = sum-temp;
            if(def >= r){
                cout << need << "\n";
            }
            else{
                cout << need + (r-def) << "\n";
            }
        }
        else{
            int temp = *it;
            int def = sum-temp;
            if(def >= r){
                cout << "0\n";
            }
            else{
                if(it != a.begin()){
                    it--;
                    temp = *it;
                    int need = l-temp;
                    int d2 = sum-temp;
                    if(d2 >= r && need <= (r-def)){
                        cout << need << "\n";
                        continue;
                    }
                    if(d2 >= r && need > (r-def)){
                        cout << r-def << "\n";
                        continue;
                    }
                    if(d2 < r){
                        if(need+(r-d2) < (r-def)){
                            cout << need+(r-d2) << "\n";
                        }
                        else{
                            cout << r-def << "\n";
                        }
                    }
                }
                else{
                    cout << r-def << "\n";
                }
            }
        }
    }
}

int32_t main(){
    FIO;
    // w(t){
        solve();
    // }
    return 0;
}
