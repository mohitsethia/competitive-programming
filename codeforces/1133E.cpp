#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        while(i + cnt[i] < n && a[i+cnt[i]]-a[i] <= 5){
            cnt[i]++;
        }
    }
    vector<vector<int> > dp(n+1, vector<int>(k+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j+1 <= k){
                dp[i+cnt[i]][j+1] = max(dp[i+cnt[i]][j+1], dp[i][j] + cnt[i]);
            }
        }
    }
    cout << dp[n][k] << "\n";
    return 0;
}
