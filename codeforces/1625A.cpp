#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, l;
        cin >> n >> l;
        vector<int> v(l+1);
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            int c = 0;
            while(x) {
                if(x%2) {
                    v[c]++;
                }
                x /= 2;
                c++;
            }
        }
        int ans = 0;
        for(int i = l-1; i >= 0; i--) {
            ans = ans*2 + (v[i] > n/2);
        }
        cout << ans << "\n";
    }
    return 0;
}
