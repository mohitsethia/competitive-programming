#include <iostream>
#include<algorithm>
#include<vector>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, x, pos; cin >> n >> x >> pos;
	vector<int> a(n, -1);
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (mid <= pos) {
			l = mid + 1;
			a[mid] = 0;
		} else {
			r = mid;
			a[mid] = 1;
		}
	}
	int c0 = 0, c1 = 0;
	for (int i = 0; i < n; i++) {
		if (i == pos) {
			continue;
		}
		if (a[i] == 1) {
			c1++;
		}
		if (a[i] == 0) {
			c0++;
		}
	}
	const int P = 1e9 + 7;
	int ans = 1;
	for (int i = x - 1; i >= x - c0; i--) {
		ans = ans * 1LL * i % P;
	}
	for (int i = n - x; i >= n - x - c1 + 1; i--) {
		ans = ans * 1LL * i % P;
	}
	for (int i = 1; i <= n - c0 - c1 - 1; i++) {
		ans = ans * 1LL * i % P;
	}
	cout << ans << endl;
	return 0;
}

