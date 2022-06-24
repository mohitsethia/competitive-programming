#pragma GCC optimize("O2")
#pragma GCC target("sse4")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
/*
vector<vector<int> > dp(5001, vector<int>(5001, -1));
int calc(int i, int j, string& a, string& b){
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = min(calc(i-1, j-1, a, b) + ((a[i-1] == b[j-1]) ? 0 : 1), min(calc(i-1, j, a, b) + 1, calc(i, j-1, a, b) +1 ));
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    //cout << calc(n, m, a, b) << endl;
    /*
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= m ;j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
        }
    }
    cout << dp[n][m] << endl;
    */
    vector<int> pre(n+1), curr(n+1);
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++){
        curr[0] = i;
        for(int j = 1; j <= n; j++){
            if(b[i-1] == a[j-1]){
                curr[j] = pre[j-1];
            }
            else{
                curr[j] = min(pre[j], min(pre[j-1], curr[j-1])) + 1;
            }
        }
        pre = vector<int>(n+1);
        swap(pre, curr);
    }
    cout << pre[n] << "\n";
    return 0;
}
