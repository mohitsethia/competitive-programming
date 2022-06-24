#include<iostream>
#include<vector>
using namespace std;
int profit(int wines[], int i, int j, int y, int dp[][100]){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != 0){
        return dp[i][j];
    }
    int op1 = wines[i]*y + profit(wines, i+1, j, y+1, dp);
    cout << "year " << y << " wine " << wines[i] << " i " << i << " j " << j << " op1 " << op1 << endl;
    int op2 = wines[j]*y + profit(wines, i, j-1, y+1, dp);
    cout << "op1 " << op1 << " op2 " << op2 << " year " << y << " wine " << wines[j] << " i " << i << " j " << j << endl;
    return dp[i][j] = max(op1, op2);
}
int main(){
    int dp[100][100] = {0};
    int wines[] = {2, 3, 5, 1, 4};
    int n = sizeof(wines)/sizeof(int);
    int y = 1;
    cout << profit(wines, 0, n-1, y, dp);
    return 0;
}
