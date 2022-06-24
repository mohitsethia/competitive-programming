#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    vector<pair<int, int>> b(m+1);
    vector<int> pref(m+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b.begin()+1, b.end());
    for(int i = 1; i <= m; i++) {
        pref[i] = pref[i-1] + b[i].second;
    }
    for(int i = 1; i <= n; i++){
        int x = a[i];
        pair<int, int> p = {x+1, 0};
        auto idx = lower_bound(b.begin()+1, b.end(), p) - b.begin();
        idx--;
        int ans = pref[idx];
        cout << ans << " ";
    }
    return 0;
}
