#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char> > s(n+1, vector<char>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> s[i][j];
        }
    }
    if(s[1][1] == '*' || s[n][n] == '*'){
        cout << 0 << endl;
        return 0;
    }
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == 1 && j == 1){
                continue;
            }
            if(s[i][j] == '*'){
                continue;
            }
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
