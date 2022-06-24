#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long 
int dp[501][501];
int a[501];
int n, m, b, mod, i, j, k, res;

signed main(){
    cin >> n >> m >> b >> mod;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(i= 0; i < n; i++){
        for(j = 0; j < m; j++){
            for(k = 0; k <= b-a[i]; k++){
                dp[j+1][k+a[i]] = (dp[j+1][k+a[i]] + dp[j][k]) % mod;
            }
        }
    }
    for(i = 0; i <= b; i++){
        res += dp[m][i];
        res %= mod;
    }
    cout << res << "\n";
    return 0;
}
