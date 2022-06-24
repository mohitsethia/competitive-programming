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

int N = 1e5;
vector<bool> is_prime(N+1, true);
void primes(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

int32_t main(){
    FIO;
    primes();
    w(t){
        int n;
        string s;
        cin >> n >> s;
        bool done = false;
        int cnt[10] = {0};
        bool cantfindany = false;
        for(int i = 0; i < n; i++){
            if(!is_prime[s[i]-'0']){
                cout << "1\n";
                cout << (s[i]-'0') << "\n";
                done = true;
                break;
            }
            cnt[s[i]-'0']++;
        }
        if(!done){
            for(int i = 1; i < 10; i++){
                if(cnt[i] > 1){
                    cout << "2\n";
                    cout << i << i << "\n";
                    done = true;
                    break;
                }
            }
        }
        if(!done){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    if(i == j) continue;
                    int num = (s[i] - '0')*10 + (s[j] -'0');
                    if(!is_prime[num]){
                        cout << "2\n";
                        cout << num << "\n";
                        done = true;
                        break;
                    }
                }
                if(done) break;
            }
        }
        if(!done){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    for(int k = j+1; k < n; k++){
                        int num = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
                        if(!is_prime[num]){
                            cout << "3\n";
                            cout << num << "\n";
                            break;
                        }
                    }
                    if(done) break;
                }
                if(done) break;
            }
        }
        if(!done){
            for(int i = 0; i < n; i++){
                for(int j = i+1; j < n; j++){
                    for(int k = j+1; k < n; k++){
                        for(int l = k+1; l < n; l++){
                            int num = (s[i]-'0')*1000 + (s[j]-'0')*100 + (s[k]-'0')*10 + (s[l]-'0');
                            if(!is_prime[num]){
                                cout << "4\n";
                                cout << num << "\n";
                                done = true;
                                break;
                            }
                        }
                        if(done) break;
                    }
                    if(done) break;
                }
                if(done) break;
            }
        }
        if(!done && cantfindany){
            cout << "1\n1\n";
            continue;
        }
    }
    return 0;
}
