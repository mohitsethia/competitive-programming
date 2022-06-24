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
#include<chrono>
#include<random>

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

int alphabetDistance(char a, char b){
    return min(abs((int)a-(int)b), 26-abs((int)a-(int)b));
}

int32_t main(){
    FIO;
    int n, p;
    string s;
    cin >> n >> p >> s;
    if(p > n/2){
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n-i-1]);
        }
        p = n-p+1;
    }
    p--;
    vi shifts(n+1, 0);
    for(int i = 0; i < n/2; i++){
        shifts[i] += alphabetDistance(s[i], s[n-i-1]);
    }
    int cnt = 0, start = p, end = p;
    for(int& i: shifts){
        cnt += i;
    }
    for(int i = 0; i < n; i++){
        if(shifts[i]){
            start = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--){
        if(shifts[i]){
            end = i;
            break;
        }
    }
    cout << cnt + (end-start) + min(abs(p-end), abs(p-start)) << endl;
    return 0;
}
