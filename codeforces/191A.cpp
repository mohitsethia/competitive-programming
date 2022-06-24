#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int dp[26][26];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int r = s[s.length()-1]-'a';
        int l = s[0]-'a';
        for(int j = 0; j < 26; j++){
            if(dp[j][l] != 0){
                dp[j][r] = max(dp[j][r], dp[j][l] + (int)s.length());
            }
        }
        dp[l][r] = max(dp[l][r], (int)s.length());
    }
    int ans = 0;
    for(int i = 0; i < 26; i++){
        ans = max(ans, dp[i][i]);
    }
    cout << ans << "\n";
    return 0;
}
