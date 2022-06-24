#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, x;
        cin >> n >> k >> x;
        string s;
        cin >> s;
        vector<pair<string, int>> base;
        int count = 0;
        string temp = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                count += k;
            }
            else {
                if(count) {
                    base.push_back({temp, count});
                    temp = "";
                }
                temp += s[i];
                count = 0;
            }
        }
        if(count) {
            base.push_back({temp, count});
            temp = "";
        }
        if(temp.size() > 0) {
            base.push_back({temp, 0});
        }
        int sz = base.size();
        int num = x-1;
        vector<int> nums(sz);
        for(int i = sz-1; i >= 0; i--) {
            nums[i] = num % (base[i].second + 1);
            num /= (base[i].second + 1);
        }
        string ans = "";
        for(int i = 0; i < sz; i++) {
            ans += base[i].first;
            ans += string(nums[i], 'b');
        }
        cout << ans << "\n";
    }
    return 0;
}
