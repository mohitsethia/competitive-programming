#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> v(1001, 1e9);
    v[1] = 0;
    for(int i = 1; i < 1001; i++) {
        for(int j = 1; j <= i; j++) {
            if(i + i/j <= 1000) {
                v[i + i/j] = min(v[i + i/j], v[i]+1);
            }
        }
    }
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> c(n);
        vector<int> w(n);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            w[i] = v[x];
        }
        for(int i = 0; i < n; i++) {
            cin >> c[i];
        }
        // k = min(k, 12*n);
        vector<int> dp(k+1);
        for(int i = 0; i < n; i++) {
            for(int j = k; j >= w[i]; j--) {
                dp[j] = max(dp[j], c[i]+dp[j-w[i]]);
            }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}
