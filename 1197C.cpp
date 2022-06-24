#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    for(int i = 1; i < n; i++) v.push_back(a[i-1]-a[i]);
    sort(v.begin(), v.end());
    int res = a[n-1]-a[0];
    for(int i = 0; i+1 < k; i++) res += v[i];
    cout << res << "\n";
    return 0;
}
