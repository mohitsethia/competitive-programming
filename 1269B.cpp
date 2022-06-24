#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    int ans = m;
    for(int j = 0; j < n; j++) {
        int x = (b[j]-a[0] + m) % m;
        for(int i = 0; i < n; i++) {
            v[i] = (a[i]+x)%m;
        }
        sort(v.begin(), v.end());
        bool equal = true;
        for(int i = 0; i < n; i++) {
            if(v[i] != b[i]) {
                equal = false;
                break;
            }
        }
        if(equal) {
            ans = min(ans, x);
        }
    }
    cout << ans << "\n";
    return 0;
}
