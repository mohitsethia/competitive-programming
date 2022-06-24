#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int N = 3e5+1;
int dp[N][3];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i].first >> a[i].second;
        }
        for(int i = 0; i < 3; i++) dp[0][i] = i*a[0].second;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < 3; j++){
                int mn = 1e18;
                for(int k = 0; k < 3; k++){
                    if(a[i-1].first + k != a[i].first + j){
                        mn = min(mn, dp[i-1][k] + j*a[i].second);
                    }
                }
                dp[i][j] = mn;
            }
        }
        int ans = 1e18;
        for(int i = 0; i < 3; i++) ans = min(ans, dp[n-1][i]);
        cout << ans << "\n";
    }
    return 0;
}
