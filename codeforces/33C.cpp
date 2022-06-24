#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N], qq[N + 1];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> aa[i];
    for (int a = 0, i = n - 1; i >= 0; i--)
        qq[i] = a -= aa[i];
    int ans = 0;
    for (int a = 0, b = 0, i = 0; i < n; i++) {
        b = max(b + aa[i], a -= aa[i]);
        ans = max(ans, b + qq[i + 1]);
    }
    cout << ans << '\n';
    return 0;
}
