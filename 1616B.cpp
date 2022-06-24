#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        if(n <= 1) {
            cout << s+s << "\n";
            continue;
        }
        else if(s[0] <= s[1]) {
            string ans = "";
            ans += s[0];
            ans += s[0];
            cout << ans << "\n";
            continue;
        }
        int i = 0;
        for(i = 1; i < n; i++) {
            if(s[i] > s[i-1]) break;
        }
        string ans = s.substr(0, i);
        string r = ans;
        reverse(r.begin(), r.end());
        cout << ans+r << "\n";
    }
    return 0;
}
