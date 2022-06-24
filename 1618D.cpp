#include <algorithm>
#include <iostream>

using namespace std;

#define int long long

int32_t main() {
	int t;
    cin >> t;
	while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        int i = 0, ans = 0;
        for(int i = 0; i < k; i++) {
            ans += a[i+k]/a[i];
        }
        for(int i = 2*k; i < n; i++) {
            ans += a[i];
        }
        cout << ans << "\n";
	}
	return 0;
}

