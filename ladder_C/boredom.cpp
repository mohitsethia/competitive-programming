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
        mii m;
        vi f(100005, 0);
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            m[x]++;
        }
        for(mii::iterator it = m.begin(); it != m.end(); it++){
            v.pb(mp(it->first, it->second));
        }
        for(int i = 0; i < v.size(); i++){
            int pr = i-1;
            while(pr >= 0 && v[pr].ff+1 == v[i].ff) pr--;
            if(pr == -1) f[i] = v[i].ff * v[i].ss;
            else f[i] = f[pr] + v[i].ff * v[i].ss;
            if(i != 0) f[i] = max(f[i], f[i-1]);
        }
        cout << f[v.size()-1] << endl;
    }
    return 0;
}
