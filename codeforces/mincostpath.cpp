#include<iostream>
using namespace std;
int dp[10000][10000] = {};
int cost[10000][10000], row, col;
int min_cost(int r, int c){
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(i == 0 && j == 0){
                dp[i][j] = cost[i][j];
            }
            else if(i == 0){
                dp[i][j] = dp[0][j-1] + cost[0][j];
            }
            else if(j == 0){
                dp[i][j] = dp[i-1][0] + cost[i][0];
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];
            }
        }
    }
    return dp[r-1][c-1];
}
int main(){
    cin >> row >> col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> cost[i][j];
        }
    }
    int ans = min_cost(row, col);
    cout << ans << endl;
    return 0;
}
