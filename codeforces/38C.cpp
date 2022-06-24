#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int n, l;
    cin >> n >> l;
    int ans = 0;
    int a[n];
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    for(int x = l; x <= mx; x++) {
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += a[i]/x;
        }
        ans = max(ans, res*x);
    }
    cout << ans << "\n";
    return 0;
}
