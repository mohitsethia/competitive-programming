#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = -1;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            ans = max(ans, a[i]);
        }
        for(int c1 = 0; c1 <= 3; c1++) {
            for(int c2 = 0; c2 <= 3; c2++) {
                int max_best = -1;
                int ok = 0;
                for(auto x: a) {
                    int best = -1;
                    for(int t1 = 0; t1 <= c1; t1++) {
                        for(int t2 = 0; t2 <= c2; t2++) {
                            int rem = x-t1-2*t2;
                            if(rem >= 0 && rem%3 == 0) {
                                if(best == -1) {
                                    best = rem/3;
                                }
                                else {
                                    best = min(best, rem/3);
                                }
                            }
                        }
                    }
                    if(best != -1) {
                        ok++;
                    }
                    max_best = max(max_best, best);
                }
                if(ok == n) { 
                    ans = min(ans, max_best + c1 + c2);
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
