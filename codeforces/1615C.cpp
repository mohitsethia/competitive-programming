#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int inf = 1e18;

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string aa, bb;
        cin >> aa >> bb;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            a[i] = (aa[i]-'0');
            b[i] = (bb[i]-'0');
        }
        int ans = inf;
        for(int p = 0; p < 2; p++) {
            vector<int> c = a;
            for(int i = 0; i < n; i++) {
                c[i] ^= p;
            }
            int x = 0;
            int y = 0;
            for(int i = 0; i < n; i++) {
                if(c[i] != b[i]) {
                    if(c[i] == 1) {
                        x++;
                    }
                    else {
                        y++;
                    }
                }
            }
            if(y == x + p) {
                ans = min(ans, x+y);
            }
        }
        cout << (ans == inf ? -1 : ans) << "\n";
    }
    return 0;
}
