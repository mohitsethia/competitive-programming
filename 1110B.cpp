#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int> v;
    for(int i = 1; i < n; i++) v.push_back(a[i-1]-a[i]);
    sort(v.begin(), v.end());
    int res = a[n-1]-a[0]+1;
    for(int i = 0; i+1 < k; i++) res += v[i]+1;
    cout << res << "\n";
    return 0;
}

