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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> v;
    for(int i = 1; i <= n; i++){
        if(i%2){
            for(int j = 1; j <= m; j++){
                v.pb({i, j});
            }
        }
        else{
            for(int j = m; j > 0; j--){
                v.pb({i, j});
            }
        }
    }
    int i = 0;
    while(k > 1 && i < (int)v.size()){
        cout << "2 " << v[i][0] << " " << v[i][1] << " " << v[i+1][0] << " " << v[i+1][1] << endl;
        i += 2;
        k--;
    }
    cout << (int)v.size()-i << " ";
    for(; i < (int)v.size(); i++){
        cout << v[i][0] << " " << v[i][1] << " ";
    }
    cout << endl;
    return 0;
}
