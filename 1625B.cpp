#include <iostream>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it: mp) {
            vector<int> v = it.second;
            for(int i = 1; i < v.size(); i++) {
                ans = min(ans, v[i]-v[i-1]);
            }
        }
        if(ans == INT_MAX) ans = -1;
        else ans = n-ans;
        cout << ans << "\n";
    }
    return 0;
}
