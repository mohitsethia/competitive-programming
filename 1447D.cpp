#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int findLCS(string s, string t){
    int n = s.length(), m = t.length();
    vector<vector<int> > dp(n+1, vector<int> (m+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<vector<int> > dp(n+1, vector<int>(m+1));
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1]+2;
            }
            else{
                dp[i][j] = max(0ll, max(dp[i][j-1], dp[i-1][j])-1);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res << "\n";
    return 0;
}
