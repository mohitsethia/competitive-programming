#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, r1, c1, r2, c2;
        cin >> n >> m >> r1 >> c1 >> r2 >> c2;
        cout << min(r1 <= r2 ? r2-r1 : 2*n - r1-r2, c1 <= c2 ? c2-c1 : 2*m -c1-c2) << "\n";
    }
    return 0;
}
