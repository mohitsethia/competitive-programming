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
        if(n%7 == 0) {
            cout << n << "\n";
        }
        else {
            n /= 10;
            n *= 10;
            if(n == 0) {
                cout << "7\n";
            }
            else {
                for(int i = 0; i < 10; i++) {
                    if((n+i)%7 == 0) {
                        cout << n+i << "\n";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
