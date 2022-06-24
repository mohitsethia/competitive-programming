#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<climits>
#include<cstring>
using namespace std;
#define ll long long
#define MOHIT ios_base::sync_with_stdio(false);cin.tie(NULL);
int N = 21;
int cost[21][21];
int dp[21][(1<<21)];
ll solve(int i, int mask, int n){
    if(i == n){
        return 0;
    }
    if(dp[i][mask] != -1){
        return dp[i][mask];
    }
    ll ans = INT_MAX;
    for(int j = 0; j < n; j++){
        if(mask&(1<<j)){
            ans = min(ans, cost[j][i] + solve(i+1, (mask^(1<<j)), n));
        }
    }
    return dp[i][mask] = ans;
}
int32_t main(){
    MOHIT;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(dp, -1, sizeof dp);
        memset(cost, 0, sizeof cost);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> cost[i][j];
            }
        }
        cout << solve(0, (1<<n)-1, n) << endl;
    }
    return 0;
}
