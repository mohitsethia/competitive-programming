#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++) {
            cnt[s[i]-'a']++;
        }
        int cntPairs = 0, cntOdd = 0;
        for(int c: cnt) {
            cntPairs += c/2;
            cntOdd += c%2;
        }
        int ans = 2 * (cntPairs / k);
        cntOdd += 2 * (cntPairs % k);
        if(cntOdd >= k) {
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
