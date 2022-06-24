#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<long long> dp(n);
        long long ans = 0;
        for(int i = n-1; i >= 0; i--){
            if(a[i] + i >= n) dp[i] = a[i];
            else dp[i] += dp[i+a[i]] + a[i];
            ans = max(ans, dp[i]);
        }
        // for(int i = 0; i < n; i++) cout << dp[i] << " ";
        // cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}
