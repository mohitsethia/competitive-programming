#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << ((a+c - 2*b) % 3 == 0 ? 0 : 1) << "\n";
    }
    return 0;
}
