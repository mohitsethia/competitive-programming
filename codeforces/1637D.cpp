#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int calc(vector<int> &a) {
    int res = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        for(int j = i+1; j < (int)a.size(); j++) {
            res += (a[i]+a[j])*(a[i]+a[j]);
        }
    }
    return res;
}

int totalSum(vector<int> &a) {
    int sum = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        sum += a[i];
    }
    return sum;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int j = 0; j < n; j++) {
            cin >> b[j];
        }
        int sa = totalSum(a);
        int sb = totalSum(b);
        for(int i = 0; i < n; i++) {
            if(abs((sa-a[i]+b[i])-(sb-b[i]+a[i])) < abs(sa-sb)) {
                sa = sa-a[i]+b[i];
                sb = sb-b[i]+a[i];
                swap(a[i], b[i]);
            }
        }
        int res = calc(a);
        res += calc(b);
        cout << res << "\n";
    }
    return 0;
}
