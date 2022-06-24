#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+2), sum(n+2), a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--){
        sum[i]  = sum[i+1] + a[i];
    }
    for(int i = n-1; i >= 1; i--){
        dp[i] = max(dp[i+1], sum[i+1]-dp[i+1]);
    }
    int res = max(dp[1], sum[1]-dp[1]);
    cout << sum[1]-res << " " << res << endl;
    return 0;
}
