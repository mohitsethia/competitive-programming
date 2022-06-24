#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int d[n];
    for(int i = 0; i+1 < n; i++) {
        cin >> d[i];
    }
    d[n-1] = 0;
    int a, b;
    cin >> a >> b;
    a--, b--;
    int ans = 0;
    for(int i = a; i < b; i++) {
        ans += d[i];
    }
    cout << ans << "\n";
    return 0;
}
