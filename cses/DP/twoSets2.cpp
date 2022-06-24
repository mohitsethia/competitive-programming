#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
/*
vector<vector<int> > dp(501, vector<int>(150000, -1));
ll solve(int n, int sum){
    if(sum < 0 || n == 0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    return dp[n][sum] = (solve(n-1, sum-n)+solve(n-1, sum))%mod;
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    if(sum%2){
        cout << 0 << endl;
        return 0;
    }
//    cout << solve(n, sum/2) << endl;
    sum /=2;
    vector<vector<int> > dp(n+1, vector<int> (sum+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = dp[i-1][j];
            if(j-i >= 0){
                (dp[i][j] += dp[i-1][j-i])%=mod;
            }
        }
    }
    cout << dp[n-1][sum] << endl;
    return 0;
}
