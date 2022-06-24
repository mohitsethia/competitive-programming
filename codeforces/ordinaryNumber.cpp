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
        int n;
        cin >> n;
        if(n < 10){
            cout << n << endl;
            continue;
        }
        if(n < 111){
            cout << min(n, 100ll)/11 + 9 << endl;
        }
        else if(n < 1111){
            cout << min(n, 1000ll)/111 + 18 << endl;
        }
        else if(n < 11111){
            cout << min(n, 10000ll)/1111 + 27 << endl;
        }
        else if(n < 111111){
            cout << min(n, 100000ll)/11111 + 36 << endl;
        }
        else if(n < 1111111){
            cout << min(n, 1000000ll)/111111 + 45 << endl;
        }
        else if(n < 11111111){
            cout << min(n, 10000000ll)/1111111 + 54 << endl;
        }
        else if(n < 111111111){
            cout << min(n, 100000000ll)/11111111 + 63 << endl;
        }
        else if(n < 1111111111){
            cout << min(n, 1000000000ll)/111111111 + 72 << endl;
        }
    }
    return 0;
}
