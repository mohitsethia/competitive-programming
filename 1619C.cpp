#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        string s, t;
        cin >> s >> t;
        string ans;
        int j = t.size() - 1;
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (j < 0) {
                cout << "-1\n";
                flag = true;
                break;
            }
            int x = s[i] - '0';
            int y = t[j] - '0';
            int z = (y - x + 10) % 10;
            ans += char(z + '0');
            if (x + z >= 10) {
                if (j == 0) {
                    cout << "-1\n";
                    flag = true;
                    break;
                }
                int num = (t[j - 1] - '0') * 10 + (t[j] - '0');
                if (num != x + z) {
                    cout << "-1\n";
                    flag = true;
                    break;
                }
                j -= 2;
            }
            else {
                j--;
            }
        }
        if(flag) continue;
        while (j >= 0) {
            ans += t[j];
            j--;
        }
        while (ans.back() == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}
