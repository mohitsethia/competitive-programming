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
    w(t){
        int n, l, r, c;
        cin >> n >> l >> r;
        vi lcnt(n+1, 0), rcnt(n+1, 0);
        for(int i = 1; i <= n; i++){
            cin >> c;
            if(i <= l) lcnt[c]++;
            else rcnt[c]++;
        }
        for(int i = 1; i <= n; i++){
            int mn = min(lcnt[i], rcnt[i]);
            lcnt[i] -= mn;
            rcnt[i] -= mn;
            l -= mn, r -= mn;
        }
        if(l < r){
            swap(lcnt, rcnt);
            swap(l, r);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int extra = l-r;
            int canDo = lcnt[i]/2; //also checks if there are left socks
            int done = min(canDo*2, extra);
            ans += done/2;
            l -= done;
        }
        ans += (l-r)/2 + (l+r)/2;
        cout << ans << endl;
    }
    return 0;
}
