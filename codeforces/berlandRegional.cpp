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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi u(n), s(n);
        for(int i = 0; i < n; i++){
            cin >> u[i];
            --u[i];
        }
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        vector<vi> bst(n);
        for(int i = 0; i < n; i++){
            bst[u[i]].push_back(s[i]);
        }
        for(int i = 0; i < n; i++){
            sort(bst[i].begin(), bst[i].end(), greater<int>());
        }
        vector<vi> pr(n, vi(1, 0));
        for(int i = 0; i < n; i++){
            for(int& x: bst[i]){
                pr[i].push_back(pr[i].back()+x);
            }
        }
        vi ans(n);
        for(int i = 0; i < n; i++){
            for(int k = 1; k <= bst[i].size(); k++){
                ans[k-1] += pr[i][bst[i].size()/k * k];
            }
        }
        for(int& x: ans){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
