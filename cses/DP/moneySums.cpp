#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum = 0;
    for(int &e: coins){
        cin >> e;
        sum += e;
    }
    vector<vector<bool> > dp(n+1, vector<bool>(sum+1));
    //dp[n][s] = dp[n-1][s] + dp[n-1][s-coins[n]]
//    0 1 2 3 4 5 6 7 8 9
//  0 1 0 0 0 0 0 0 0 0 0  
//  4 1 0 0 0 1 0 0 0 0 0 
//  2 1 0 1 0 1 0 1 0 0 0
//  5 1 0 1 0 1 1 1 1 0 1
//  2 1 0 1 0 1 1 1 1 1 1
    dp[0][0] = true;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(j == 0){
                dp[i][j] = true;
            }
            else{
                if(j-coins[i-1] >= 0){
                    dp[i][j] = dp[i-1][j-coins[i-1]];
                }
                dp[i][j] = dp[i][j] || dp[i-1][j];
            }
            if(i == n && j != 0 && dp[i][j]){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= sum; i++){
        if(dp[n][i]){
            cout << i << " ";
        }
    }
    return 0;
}
