#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int> > dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                if(c == '*'){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = 1; j < m-1; j++){
                if(dp[i][j] == 0) continue;
                dp[i][j] = min(dp[i+1][j], min(dp[i+1][j-1], dp[i+1][j+1]))+1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += dp[i][j];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
