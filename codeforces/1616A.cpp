#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> cnt(250);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(cnt[x+100]) {
                x = -x;
                if(cnt[x+100]) continue;
                cnt[x+100] = 1;
                ans++;
            }
            else{
                cnt[x+100] = 1;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
