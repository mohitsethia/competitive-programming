#include<iostream>
using namespace std;
int dp[100][100] = {};
int optimaldp(int *coins, int i, int j){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    int sum = 0;
    int s1 = min(optimaldp(coins, i+2, j), optimaldp(coins, i+1, j-1));
    int s2 = min(optimaldp(coins, i, j-2), optimaldp(coins, i+1, j-1));
    sum += max(coins[i] + s1, coins[j] + s2);
    return dp[i][j] = sum;
}   
int main(){
    int n, sum = 0;
    cin >> n;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
        sum += coins[i];
    }
    int ans = optimaldp(coins, 0, n - 1);   
    cout << max(ans, sum-ans) << endl;
    return 0;
}
