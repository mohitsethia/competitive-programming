#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        vector<vector<int> > dp(n+1, vector<int>(k+1, 1));
        vector<int> last_idx(mx+1, -1);
        vector<int> mx_ans(k+1);
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = k; j >= 0; j--){
                if(j > 0){
                    dp[i][j] = mx_ans[j-1]+1;
                }
                if(last_idx[a[i]] != -1){
                    dp[i][j] = max(dp[i][j], dp[last_idx[a[i]]][j]+1);
                }
                mx_ans[j] = max(mx_ans[j], dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
            last_idx[a[i]] = i;
        }
        cout << ans << "\n";
    }
    return 0;
}
