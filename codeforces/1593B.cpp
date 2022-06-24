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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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


bool isdivisible(string& newstr, long long K)
{
    // int num = stoi(newstr);
    // if(num%K == 0) return true;
    // else return false;
    long long num = 0;

    for (int i = 0; i < (int)newstr.size(); i++) {
        num = num * 10 + newstr[i] - '0';
    }

    if (num % K == 0)
        return true;

    else
        return false;
}

void findLargestNo(string& str, string& newstr,string& ans, int index,long long K)
{
 
    if (index >= (int)str.length()) {
        if (isdivisible(newstr, K)) {
            if ((ans < newstr && ans.length() == newstr.length()) || newstr.length() > ans.length()) {
                ans = newstr;
            }
        }
        return;
    }
 
    string x = newstr + str[index];
    findLargestNo(str, x, ans, index + 1, K);
    findLargestNo(str, newstr, ans, index + 1, K);
}

void solve(){
    int n;
    cin >> n;
    // if(n%25 == 0){
        // cout << "0\n";
        // return;
    // }
    string s = to_string(n);
    int p = sz(s);
    int k = 0;
    int ans = 0;
    for(int i = p-1; i >= 0; i--){
        if(s[i] == '0'){
            k = i;
            for(int j = i-1; j >= 0; j--){
                if(s[j] == '0' || s[j] == '5') break;
                ans++;
            }
            break;
        }
        ans++;
    }
    int ans1 = 0;
    k = 0;
    for(int i = p-1; i >= 0; i--){
        if(s[i] == '5'){
            k = i;
            for(int j = k-1; j >= 0; j--){
                if(s[j] == '2' || s[j] == '7'){
                    k = j;
                    break;
                }
                ans1++;
            }
            break;
        }
        ans1++;
    }
    cout << min(ans1, ans) << "\n";
    /*
    string ans = "", newstr = "";
    int k = 25;
    findLargestNo(s, newstr, ans, 0, k);
    if(ans != ""){
        cout << p-sz(ans) << "\n";
    }
    else{
        cout << "-1\n";
    }
    */
}

int32_t main(){
    FIO;
    w(t){
        solve();
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
