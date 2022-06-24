#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int inf = 1e9+7;

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxR = 0, minL = inf, costL = inf, costR = inf;
        int maxLen = 0, costLen = inf;
        for(int i = 0; i < n; i++) {
            int l, r, c;
            cin >> l >> r >> c;
            if(l < minL) {
                minL = l, costL = inf;
            }
            if(l == minL) {
                costL = min(costL, c);
            }
            if(r > maxR) {
                maxR = r, costR = inf;
            }
            if(r == maxR) {
                costR = min(costR, c);
            }
            if(r-l+1 > maxLen) {
                maxLen = r-l+1, costLen = inf;
            }
            if(maxLen == r-l+1) {
                costLen = min(costLen, c);
            }
            int ans = costL+costR;
            if(maxLen == maxR-minL+1) {
                ans = min(ans, costLen);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
