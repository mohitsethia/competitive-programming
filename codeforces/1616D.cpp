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
        for(int &i: a) cin >> i;
        int x;
        cin >> x;
        vector<int> pref(n+1);
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + a[i]-x;
        }
        int ans = n;
        int max_unused = 0;
        for(int i = 2; i <= n; i++) {
            if(pref[i] < max_unused) {
                ans--;
                max_unused = pref[i];
                i++;
            }
            else {
                max_unused = max(max_unused, pref[i-1]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
