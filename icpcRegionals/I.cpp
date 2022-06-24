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
/*
const int N = 1e6+1;
int par[N];
int find(int x){
    if(par[x] == x){
        return x;
    }
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    int p = find(x);
    int q = find(y);
    par[q] = q;
}
*/

const int N = 1e6+1;
bool is_prime[N];
int prime_divisor[N];

void sieve(){
    for(int p = 2; p < N; p++){
        is_prime[p] = true;
    }
    for(int p = 2; p < N; p++){
        if(is_prime[p]){
            prime_divisor[p] = p;
            for(int a = 2*p; a < N; a += p){
                prime_divisor[a] = p;
                is_prime[a] = false;
            }
        }
    }
}
 
vector<pair<int, int> > factorization(int x){
    vector<pair<int, int> > v;
    while(x != 1){
        int cnt = 0;
        int p = prime_divisor[x];
        while(x%p == 0){
            x /= p;
            cnt++;
        }
        v.emplace_back(p, cnt);
    }
    return v;
}

void solve(){
    int n;
    cin >> n;
    vi r(n);
    map<int, int> fr;
    map<int, vector<pair<int, int> > > all;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> r[i];
        s.insert(r[i]);
            for(auto it: factorization(r[i])){
                fr[it.first] += it.second;
                all[r[i]].push_back(it);
            }
    }
    int ans = 0;
    if((int)s.size() == 1){
        cout << ans << "\n";
        return;
    }
    sort(r.begin(), r.end(), greater<int>());
    for(int i = n-1; i >= 0; i--){
        if(r[i] == 1){
            for(int small = 2; small < N; small += (small&1)+1){
                if(fr.find(small) != fr.end()){
                    ans += small;
                    fr[small]++;
                    break;
                }
            }
        }
        else{
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(r[i] == 1) break;
        bool found = false;
        for(auto it: all[r[i]]){
            if(fr[it.first] == it.second) continue;
            else{
                found = true;
                break;
            }
        }
        if(!found){
            int small = 2;
            for(; small < N; small += (small&1)+1){
                if(fr.find(small) != fr.end()){
                    ans += small;
                    fr[small]++;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}

int32_t main(){
    FIO;
    sieve();
    w(t){
        solve();
    }
    return 0;
}
