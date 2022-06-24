#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> p(n, vector<int>(m));
        int maxx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> p[i][j];
                maxx = max(maxx, p[i][j]);
            }
        }
        auto check = [&](int x) {
            vector<bool> bought(m, false);
            bool pair = false;
            for(int i = 0; i < n; i++) {
                int pairs = 0;
                for(int j = 0; j < m; j++) {
                    if(p[i][j] >= x) {
                        bought[j] = true;
                        pairs++;
                    }
                }
                if(pairs > 1) pair = true;
            }
            if(!pair && m > 1) return false;
            bool ans = true;
            for(auto b: bought) {
                ans = ans && b;
            }
            return ans;
        };
        int l = 1, r = maxx+10;
        while(r-l > 1) {
            int mid = (l+r)/2;
            if(check(mid)) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        cout << l << "\n";
    }
    return 0;
}
