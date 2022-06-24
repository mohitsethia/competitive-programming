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
        vector<vector<bool>> vis(n+1, vector<bool>(n+1));
        vector<int> l(n), r(n);
        for(int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            vis[l[i]][r[i]] = true;
        }
        for(int i = 0; i < n; i++) {
            for(int j = l[i]; j <= r[i]; j++) {
                if((j == l[i] || vis[l[i]][j-1]) && (j == r[i] || vis[j+1][r[i]])) {
                    cout << l[i] << " " << r[i] << " " << j << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
