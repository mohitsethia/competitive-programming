#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    vector<int> diff;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sum += a;
        diff.push_back(a-b);
    }
    sort(diff.rbegin(), diff.rend());
    for (int i = 0; i < n; i++) {
        if (sum <= m) {
            cout << i << endl;
            return 0;
        }
        sum -= diff[i];
    }
    if (sum <= m) cout << n << endl;
    else cout << -1 << endl;
}
