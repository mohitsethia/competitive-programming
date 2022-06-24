#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int k, n, a, b;
        cin >> k >> n >> a >> b;
        int l = 0, r = n;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;
            int x = mid*a;
            int y = (n-mid)*b;
            if(k - x - y > 0) {
                ans = mid;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
