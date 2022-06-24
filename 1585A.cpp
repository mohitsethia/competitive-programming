#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int *a = new int[n];
        int ans = 1;
        bool died = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) {
                if(i > 0 && a[i-1] == 0) {
                    died = true;
                }
                continue;
            }
            if(a[i] == 1) {
                if(i > 0 && a[i-1] == 1) {
                    ans += 5;
                }
                else {
                    ans++;
                }
            }
        }
        if(died) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}
