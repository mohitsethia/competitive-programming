#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int mod = 998244353;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] *= (i+1)*(n-i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        a[i] %= mod;
        b[i] %= mod;
        int crn = a[i]*b[i];
        crn %= mod;
        ans += crn;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}
