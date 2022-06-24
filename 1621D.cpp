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
        int a[2*n][2*n];
        for(int i = 0; i < n*2; i++) {
            for(int j = 0; j < n*2; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 1e9+7;
        // minimum in the 4 corners of the top right and bottom left cells
        ans = min({ans, a[0][n], a[0][n+n-1], a[n-1][n], a[n-1][n+n-1], a[n][0], a[n+n-1][0], a[n][n-1], a[n+n-1][n-1]});
        for(int i = n; i < n*2; i++) {
            for(int j = n; j < n*2; j++) {
                ans += a[i][j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
