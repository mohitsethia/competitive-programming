#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> dp(n+1);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        if(i == 2) dp[i] = 2;
        else{
            dp[i] += 2*dp[i-1];
            dp[i]++;
            dp[i] %= m;
        }
        int v = dp[i]-dp[i-1] + m;
        for(int j = 2*i; j <= n; j += i){
            dp[j] += v;
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
