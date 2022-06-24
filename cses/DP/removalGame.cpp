#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
int n;
vector<ll> arr;
/*
vector<vector<ll> > dp(5010, vector<ll>(5010, -1));
ll solve(int i, int j){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return max(arr[i] + min(solve(i+2, j), solve(i+1, j-1)), arr[j] + min(solve(i+1, j-1), solve(i, j-2)));
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //cout << solve(0, n-1) << endl;
    vector<vector<ll> > dp(n, vector<ll> (n));
    for(int gap = 0; gap < n; gap++){
        for(int i = 0, j = gap; j < n; i++, j++){
            if(gap == 0){
                dp[i][j] = arr[i];
            }
            else if(gap == 1){
                dp[i][j] = max(arr[i], arr[j]);
            }
            else{
                ll val1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
                ll val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);
                dp[i][j] = max(val1, val2);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
