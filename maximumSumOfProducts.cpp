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

int32_t main(){
    FIO;
    int t = 1;
    while(t--){
        int n;
        cin >> n;
        vi pr(n+1, 0), a(n), b(n);
        for(int& x: a){
            cin >> x;
        }
        for(int& x: b){
            cin >> x;
        }
        for(int i = 0; i < n; i++){
            pr[i+1] = pr[i] + a[i]*b[i];
        }
        int ans = pr[n];
        for(int c = 0; c < n; c++){
            int cur = a[c]*b[c];
            //odd length
            for(int l = c-1, r = c+1; l >= 0 && r < n; l--, r++){
                cur += a[l]*b[r];
                cur += a[r]*b[l];
                ans = max(ans, cur + pr[l] + (pr[n] - pr[r+1]));
            }
            cur = 0;
            //even length
            for(int l = c, r = c+1; l >= 0 && r < n; l--, r++){
                cur += a[l]*b[r];
                cur += a[r]*b[l];
                ans = max(ans, cur + pr[l] + (pr[n] - pr[r+1]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
