#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long

bool check(int hc, int dc, int hm, int dm) {
    int hero = hm/dc + (hm%dc > 0);
    int monster = hc/dm + (hc%dm > 0);
    return hero <= monster;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int hc, dc;
        int hm, dm;
        cin >> hc >> dc >> hm >> dm;
        int k, w, a;
        cin >> k >> w >> a;
        bool found = false;
        for(int i = 0; i <= k; i++) {
            int newdc = dc+w*i;
            int newhc = hc+a*(k-i);
            if(check(newhc, newdc, hm, dm)) {
                // cout << newhc << " " << newdc << "\n";
                found = true;
                break;
            }
        }
        if(found) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
