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
int k, n, m;
vi a(101);
vi b(101);
int32_t main(){
    FIO;
    w(t){
        cin >> k >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        int i = 0, j = 0;
        bool has = true;
        vi res;
        while(i < n && j < m){
            if(a[i] == 0){
                res.emplace_back(a[i]);
                k++;
                i++;
            }
            else if(a[i] <= k){
                res.emplace_back(a[i]);
                i++;
            }
            else if(b[j] == 0){
                res.emplace_back(b[j]);
                j++;
                k++;
            }
            else if(b[j] <= k){
                res.emplace_back(b[j]);
                j++;
            }
            else if(a[i] > k && b[j] > k){
                has = false;
                break;
            }
        }
        if(!has){
            cout << "-1\n";
        }
        else{
            while(i < n){
                if(a[i] <= k){
                    res.emplace_back(a[i]);
                    if(a[i] == 0){
                        i++;
                        k++;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    has = false;
                    break;
                }
            }
            while(j < m){
                if(b[j] <= k){
                    res.emplace_back(b[j]);
                    if(b[j] == 0){
                        j++;
                        k++;
                    }
                    else{
                        j++;
                    }
                }
                else{
                    has = false;
                    break;
                }
            }
            if(!has){
                cout << "-1\n";
            }
            else{
                for(int i = 0; i < n+m; i++){
                    cout << res[i] << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
