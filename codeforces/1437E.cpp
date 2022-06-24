#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long
using namespace std;

int LIS(int mn, int mx, vector<int> a){
    vector<int> dp;
    for(int v: a){
        if(v < mn || v > mx) continue;
        vector<int>::iterator it = upper_bound(dp.begin(), dp.end(), v);
        if(it == dp.end()) dp.push_back(v);
        else *it = v;
    }
    return dp.size();
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    vector<int> b(k);
    for (int& v : b) cin >> v, v--;
    for (int i = 1; i < k; i++) {
        if (a[b[i]] < a[b[i-1]]) {
            cout << -1 << endl;
            return 0;
        }
    }
    a.insert(a.begin(), -2e9);
    a.push_back(2e9);
    b.insert(b.begin(), -1);
    b.push_back(n);
    for (int&v : b) v++;

    int ans = 0;
    for (int i = 1; i <= k+1; i++) {
        int li = b[i-1];
        int ri = b[i];
        ans += ri-li-1 - LIS(a[li], a[ri], vector<int>(a.begin()+li+1, a.begin()+ri));
    }
    cout << ans << endl;
    return 0;
}
