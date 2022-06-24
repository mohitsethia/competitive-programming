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
#define ld              long double
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define MOD             1000000007
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
const int mod = 1e9;
ld solve(ld c, ld m, ld p, ld v, int len){
    ld ans = p/mod * len;
    if(c > 0){
        if(c > v){
            if(m > 0){
                ans += c/mod * solve(c-v, m + v/2, p + v/2, v, len+1);
            }
            else{
                ans += c/mod * solve(c-v, 0, p+v, v, len+1);
            }
        }
        else{
            if(m > 0){
                ans += c/mod * solve(0, m + c/2, p + c/2, v, len+1);
            }
            else{
                ans += c/mod * solve(0, 0, p + c, v, len+1);
            }
        }
    }
    if(m > 0){
        if(m > v){
            if(c > 0){
                ans += m/mod * solve(c + v/2, m-v, p+v/2, v, len+1);
            }
            else{
                ans += m/mod * solve(0, m-v, p + v, v, len+1);
            }
        }
        else{
            if(c > 0){
                ans += m/mod * solve(c+m/2, 0, p+m/2, v, len+1);
            }
            else{
                ans += m/mod * solve(0, 0, p+m, v, len+1);
            }
        }
    }
    return ans;
}
int32_t main(){
    FIO;
    w(t){
        ld c, m, p, v;
        cin >> c >> m >> p >> v;
        c *= mod;
        m *= mod;
        p *= mod;
        v *= mod;
        ld ans = solve(c, m, p, v, 1);
        cout << ps(ans, 15) << "\n";
    }
    return 0;
}
