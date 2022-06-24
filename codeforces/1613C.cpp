#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 1, r = k;
        int ans = 1;
        while(l <= r){
            int mid = (l+r)/2;
            int p = 0;
            for(int i = 1; i < n; i++){
                p += min(a[i] - a[i-1], mid);
            }
            p += mid;
            if(p >= k){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
