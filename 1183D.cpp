#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> mp;
        for(auto it: a) {
            mp[it]++;
        }
        vector<int> c;
        for(auto p: mp){
            c.push_back(p.second);
        }
        sort(c.rbegin(), c.rend());
        int last = 1e9;
        int s = 0;
        for(auto x: c) {
            x = min(x, last);
            x = max(x, 0ll);
            s += x;
            last = x-1;
        }
        cout << s << "\n";
    }
    return 0;
}
