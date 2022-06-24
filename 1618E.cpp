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
        vector<int> b(n);
        int sumb = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            sumb += b[i];
        }
        int val = n*(n+1)/2;
        if(sumb % val != 0) {
            cout << "NO\n";
            continue;
        }
        int suma = sumb/val;
        vector<int> a(n);
        bool bad = false;
        for(int i = n-1; i >= 0; i--) {
            int res = (b[i]-b[(i+1)%n] + suma);
            if(res % n != 0 || res <= 0) {
                bad = true;
                break;
            }
            a[(i+1)%n] = res/n;
        }
        if(bad) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for(auto it: a) {
                cout << it << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
