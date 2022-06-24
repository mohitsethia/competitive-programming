#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int dp[n][n];
    for(int i = 0; i < s.length(); i++){
        dp[i][i] = 1;
    }
    for(int l = 2; l <= s.length(); l++){
        for(int i = 0; i < s.length() - l + 1; i++){
            int j = i + l -1;
            if(l == 2 && s[i] == s[j]){
                dp[i][j] = 2;
            }
            else if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    int mx = dp[0][n-1];
    cout << n-mx << endl;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
