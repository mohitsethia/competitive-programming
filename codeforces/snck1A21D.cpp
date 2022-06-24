#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp.insert(a[i]);
        }
        if(n <= 2){
            cout << "0\n";
            continue;
        }
        sort(a.begin(), a.end());
        if(n == 3){
            cout << min(a[1]-a[0], a[2]-a[1]) << "\n";
            continue;
        }
        if(a[0] == a.back() && a[1] == a[n-2]){
            cout << "0\n";
            continue;
        }
        int l = 1, r = n-2;
        int mn1 = 0, mn2 = 0;
        for(int i = 0; i < n; i++){
            if(i < n-1) mn1 += abs(a[i]-a[(n-1)/2]);
            if(i) mn2 += abs(a[i] - a[1+(n-1)/2]);
        }
        int ans = min(mn1, mn2);
        while(l < r){
            int p = a[n-1] - a[l];
            int q = a[r] - a[0];
            ans = min(ans, abs(p - q));
            if(p <= q) r--;
            else l++;
        }
        cout << ans << "\n";
    }
    return 0;
}
