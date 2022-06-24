#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200000;

int kk[N + 1], qu[N];

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(kk, kk + n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            kk[a]++;
        }
        long long ans = 0;
        int cnt = 0, k = 0;
        for (int a = 0; a <= n; a++) {
            if (a > k) {
                while (a <= n) {
                    cout << "-1 ";
                    a++;
                }
                break;
            }
            cout << ans + kk[a] << ' ';
            k += kk[a];
            if (kk[a] == 0) {
                int b = qu[cnt - 1];
                ans += a - b;
                if (--kk[b] == 1)
                    cnt--;
            } else if (kk[a] > 1)
                qu[cnt++] = a;
        }
        cout << '\n';
    }
    return 0;
}
