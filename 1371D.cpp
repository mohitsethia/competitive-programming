#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<iomanip>

#define int long long
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int f = (k%n != 0)*2;
        vector<vector<int> > ans(n, vector<int>(n));
        for(int i = 0, c = 0; i < n && c < k; i++){
            int x = 0, y = i;
            for(int j = 0; j < n && c < k; j++, c++){
                ans[x][y] = 1;
                x = (x+1)%n;
                y = (y+1)%n;
            }
        }
        cout << f << endl;
        for (auto v : ans) {
            for (int i : v) cout << i;
            cout << endl;
        }
    }
}

