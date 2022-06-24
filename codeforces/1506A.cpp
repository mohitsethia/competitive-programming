#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int x;
        cin >> x;
        int a = (x-1)/n;
        int b = (x-1)%n;
        cout << (1 + b*m+a) << "\n";
    }
    return 0;
}
