#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k > (n+1)/2) {
            cout << "-1\n";
            continue;
        }
        vector<string> s(n, string(n, '.'));
        for(int i = 0; i < k; i++) {
            s[i*2][i*2] = 'R';
        }
        for(string st:s) {
            cout << st << "\n";
        }
    }
    return 0;
}
