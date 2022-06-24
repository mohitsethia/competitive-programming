#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

bool check(int x, vector<int> &a, int n) {
    vector<int> c = a;
    for(int i = n-1; i > 1; i--) {
        if(c[i] < x) return false;
        int d = min(a[i], c[i]-x)/3;
        c[i-1] += d;
        c[i-2] += 2*d;
    }
    return c[0] >= x && c[1] >= x;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int r = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            r = max(r, a[i]);
        }
        int ans = 0;
        int l = 0;
        while(l <= r) {
            int mid = (l+r)/2;
            if(check(mid, a, n)) {
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
