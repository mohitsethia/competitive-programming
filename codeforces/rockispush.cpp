#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MOD 1000000007
#define RIGHT 0
#define DOWN 1
#define int long long
#define MAX 2003
int dp[MAX][MAX][2];
int s[MAX][MAX][2];
int cnt[MAX][MAX][2] = {0};

int32_t main(){
    int n, m;
    cin >> n >> m;
    int Mat[n+1][m+1];
    for(int i = 0; i <= n; i++){
        memset(Mat[i], 0, sizeof(Mat[i]));
    }
    for(int row = 1; row <= n; row++){
        for(int col = 1; col <= m; col++){
            char ch;
            cin >> ch;
            Mat[row][col] = (ch == '.' ? 1 : 0);
        }
    }
    for(int row = 1; row <= n; row++){
        for(int col = m; col >= 1; col--){
            cnt[row][col][RIGHT] = cnt[row][col+1][RIGHT] + Mat[row][col];
        }
    }
    for(int col = 1; col <= m; col++){
        for(int row = n; row >= 1; row--){
            cnt[row][col][DOWN] = cnt[row+1][col][DOWN] + Mat[row][col];
        }
    }
    if(Mat[n][m] == 0){
        cout << "0" << endl;
        return 0;
    }
    if(n == 1 && m == 1){
        cout << "1" << endl;
        return 0;
    }
    dp[n][m][RIGHT] = dp[n][m][DOWN] = 1;
    s[n][m][RIGHT] = s[n][m][DOWN] = 1;
    for(int row = n; row >= 1; row--){
        for(int col = m; col >= 1; col--){
            if(row == n && col == m){
                continue;
            }
            int y = cnt[row+1][col][DOWN];
            dp[row][col][DOWN] = (s[row+1][col][RIGHT] - s[row+y+1][col][RIGHT] + MOD) % MOD;
            int x = cnt[row][col+1][RIGHT];
            dp[row][col][RIGHT] = (s[row][col+1][DOWN] - s[row][col+x+1][DOWN] + MOD) % MOD;
            s[row][col][DOWN] = (s[row][col+1][DOWN] + dp[row][col][DOWN])%MOD;
            s[row][col][RIGHT] = (s[row+1][col][RIGHT] + dp[row][col][RIGHT])%MOD;
        }
    }
    cout << (dp[1][1][DOWN] + dp[1][1][RIGHT])%MOD << endl;
    return 0;
}
