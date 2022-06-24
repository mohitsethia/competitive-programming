#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> pref(n+1);
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + a[i];
        }
        int ans = 2e18;
        for(int i = 0; i < n; i++) {
            int sum = pref[n-i] + a[0]*i;
            int curr = i;
            if(sum > k) {
                int diff = sum - k;
                curr += (diff + i) / (i+1);
            }
            ans = min(ans, curr);
        }
        cout << ans << "\n";
    }
    return 0;
}
