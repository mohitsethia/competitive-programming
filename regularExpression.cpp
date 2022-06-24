#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
    public:
    bool isMatch(string &text, string &pat){
        int n = text.length();
        int m = pat.length();
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(text[i-1] == pat[j-1] || pat[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pat[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if(pat[j-2] == '.' || pat[j-2] == text[i-1]) dp[i][j] = dp[i][j] | dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    string text, pat;
    cin >> text >> pat;
    Solution obj;
    cout << obj.isMatch(text, pat) << "\n";
    return 0;
}
