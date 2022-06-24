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

int ans;

/*
int solve(string &s, int rem1, int rem2, int score1, int score2, int t){
    if(rem1 < 0 || rem2 < 0) return INT_MAX;
    if(rem1 == 0 || rem2 == 0){
        return ans = min(ans, t);
    }
    if(rem2 < score1){
        ans = min(ans, t);
        return ans;
    }
    if(rem1 < score2){
        ans = min(ans, t);
        return ans;
    }
    if(t%2 == 0){
        if(s[t] == '1'){
            return 1 + solve(s, rem1-1, rem2, score1+1, score2, t+1);
        }
        else if(s[t] == '0'){
            return solve(s, rem1-1, rem2, score1, score2, t+1);
        }
        else{
            return min(solve(s, rem1-1, rem2, score1, score2, t+1), 1+solve(s, rem1-1, rem2, score1+1, score2, t+1));
        }
    }
    else{
        if(s[t] == '1'){
            return 1 + solve(s, rem1, rem2-1, score1, score2+1, t+1);
        }
        else if(s[t] == '0'){
            return solve(s, rem1, rem2-1, score1, score2, t+1);
        }
        else{
            return min(solve(s, rem1, rem2-1, score1, score2, t+1), solve(s, rem1, rem2-1, score1, score2+1, t+1)+1);
        }
    }
    return ans;
}
*/

void solve(string s, int t){
    if(t == (int)s.size()){
        int score1 = 0, score2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < 10; i++){
            if(i%2 == 0){
                score1 += (s[i] == '1');
                cnt1++;
            }
            else{
                score2 += (s[i] == '1');
                cnt2++;
            }
            int rem1 = 5-cnt1;
            int rem2 = 5-cnt2;
            bool one  = false, two = false;
            if((score1-score2) > rem2){
                ans = min(ans, i+1);
                one = true;
            }
            if((score2-score1) > rem1){
                ans = min(ans, i+1);
                two = true;
            }
            if(!one && !two && i == 9){
                ans = min(ans, i+1);
            }
        }
        return;
    }
    if(s[t] == '?'){
        s[t] = '1';
        solve(s, t+1);
        s[t] = '0';
        solve(s, t+1);
    }
    else{
        solve(s, t+1);
    }
}

int32_t main(){
    FIO;
    w(t){
        string s;
        cin >> s;
        ans = INT_MAX;
        int n = 5;
        solve(s, 0); 
        cout << ans << "\n";
    }
    return 0;
}
