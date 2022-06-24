#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &i: a) cin >> i;
        int ans = n;
        if(n <= 2) ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int cost = 0;
                for(int k = 0; k < n; k++) {
                    if((j-i)*(a[k]-a[i]) != (k-i)*(a[j]-a[i])) {
                        cost++;
                    }
                }
                ans = min(ans, cost);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
