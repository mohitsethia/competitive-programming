#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 1e9;
        sort(a.begin(), a.end());
        for (auto b : a) {
            int x = a[0] ^ b;
            if (x == 0) continue;
            vector<int> c;
            for (int i = 0; i < a.size(); ++i) {
                c.push_back(a[i] ^ x);
            }
            sort(c.begin(), c.end());
            if (a == c) {
                ans = min(ans, x);
            }
        }
        if (ans == 1e9) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
