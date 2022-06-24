#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int N = 2e5 + 10;

int32_t main() {
    vector<vector<int>> cnt(N, vector<int>(20));
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < 20; j++) {
            cnt[i+1][j] = cnt[i][j] + ((i >> j)&1);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        b++;
        int ans = b-a;
        for(int i = 0; i < 20; i++) {
            int ones = cnt[b][i]-cnt[a][i];
            int zeroes = b-a-ones;
            if(ones) {
                ans = min(ans, zeroes);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
