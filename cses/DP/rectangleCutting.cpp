#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<time.h>
#include<iomanip>
#include<climits>
using namespace std;
vector<vector<int> > dp(501, vector<int>(501, -1));
int solve(int a, int b){
    if(a == b){
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    int left = INT_MAX;
    for(int i = 1; i < a; i++){
        int x, y;
        if(dp[a-i][b] != -1){
            x = dp[a-i][b];
        }
        else{
            x = solve(a-i, b);
        }
        if(dp[i][b] != -1){
            y = dp[i][b];
        }
        else{
            y = solve(i, b);
        }
        left = min(left, x+y+1);
    }
    int right = INT_MAX;
    for(int j = 1; j < b; j++){
        int x, y;
        if(dp[a][b-j] != -1){
            x = dp[a][b-j];
        }
        else{
            x = solve(a, b-j);
        }
        if(dp[a][j] != -1){
            y = dp[a][j];
        }
        else{
            y = solve(a, j);
        }
        right = min(right, x+y+1);
    }
    return dp[a][b] = min(left, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
//    time_t start, end;
//    time(&start);
    cout << solve(a, b) << endl;
/*
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int> > dp(a+1, vector<int>(b+1));
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1e9;
                for(int k = 1; k < i; k++){
                    dp[i][j] = min(dp[i][j], dp[i-k][j]+dp[k][j]+1);
                }
                for(int k = 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
//    time(&end);
//    double time_taken = double(end - start);
//    cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
//    cout << " sec " << endl;
*/
    return 0;
}
