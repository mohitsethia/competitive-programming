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

int solve(int& n, int& k, vi& p){
    sort(p.begin(), p.end());
    auto ip = unique(p.begin(), p.end());
    p.resize(distance(p.begin(), ip));
    int maxx = k-p.size();
    return (maxx-2 > 0 ? maxx-2 : maxx);
}

int32_t main(){
    FIO;
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        int n, k;
        cin >> n >> k;
        vi p(n);
        for(int& x: p) cin >> x;
        double ans = solve(n, k, p);
        ans /= k;
        cout << "Case #" << tc << ": " << ps(ans, 6) << endl;

    }
    return 0;
}
