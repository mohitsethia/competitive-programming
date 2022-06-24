#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> res(2, -1);
    int reso = 1e4;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i) {
            if(reso > abs(a[i]-a[i-1])) {
                reso = abs(a[i]-a[i-1]);
                res[0] = i-1;
                res[1] = i;
            }
        }
    }
    if(reso > abs(a[n-1]-a[0])) {
        reso = abs(a[n-1]-a[0]);
        res[0] = n-1;
        res[1] = 0;
    }
    cout << res[0]+1 << " " << res[1]+1 << "\n";
    return 0;
}
