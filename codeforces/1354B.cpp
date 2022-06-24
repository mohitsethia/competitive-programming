#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int cnt[3] = {};
        int ans = 1e9;
        int l = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i]-'1']++;
            while (cnt[0] && cnt[1] && cnt[2] && cnt[s[l]-'1'] > 1) {
                cnt[s[l++]-'1']--;
            }
            if (cnt[0] && cnt[1] && cnt[2])
                ans = min(ans, i-l+1);
        }
        if (ans == 1e9) ans = 0;
        cout << ans << endl;
    }
}
