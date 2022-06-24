#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define int long long

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> work(n), boost(n);
    for(int i = 0; i < n; i++) {
        cin >> work[i];
    }
    int a;
    cin >> a;
    for(int i = 0; i < n; i++) {
        cin >> boost[i];
    }
    multiset<int> s;
    bool ch = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        s.insert(boost[i]);
        while(k < work[i] && !s.empty()) {
            ans += *s.begin();
            s.erase(s.begin());
            k += a;
        }
        if(k < work[i]) {
            ch = 0;
        }
    }
    if(ch == 0) {
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}
