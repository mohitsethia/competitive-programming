#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char ch;
            cin >> ch;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (ch == '*');
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int query = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
        cout << query << endl;
    }
    return 0;
}
