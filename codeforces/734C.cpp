#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    int x, s;
    cin >> x >> s;
    vector<int> a(m+1), b(m+1), c(k+1), d(k+1);
    a[0] = x;
    for(int i = 1; i <= m; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    for(int i = 1; i <= k; i++) cin >> c[i];
    for(int i = 1; i <= k; i++) cin >> d[i];

    auto comp = [&](int left){
        int l = 0, r = k;
        while(l < r){
            int mid = (l+r+1)/2;
            if(d[mid] <= left) l = mid;
            else r = mid-1;
        }
        return c[l];
    };

    int ans = n*x;
    for(int i = 0; i <= m; i++){
        if(s < b[i]) continue;
        ans = min(ans, (n- comp(s-b[i]))*a[i]);
    }
    cout << ans << "\n";
    return 0;
}
