#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int w, h;
        cin >> w >> h;
        int kll = 0;
        int maxx = 0;
        while(kll < 4){
            int k;
            cin >> k;
            int first;
            cin >> first;
            for(int i = 1; i+1 < k; i++){
                int waste;
                cin >> waste;
            }
            int last;
            cin >> last;
            if((last-first)*(kll < 2 ? h : w) > maxx){
                maxx = (last-first)*(kll < 2 ? h : w);
            }
            kll++;
        }
        cout << maxx << "\n";
    }
    return 0;
}
