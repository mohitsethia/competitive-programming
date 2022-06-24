#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i = 0; i < n; i++){
            cin >> h[i];
        }
        int s = h[0], e = h[0]+k;
        string ans = "YES";
        for(int i = 1; i < n-1; i++){
            int start_min = max(h[i], s-k+1);
            int end_max = k + min(e-1, h[i] + k -1);
            if(end_max - start_min < k){
                ans = "NO";
                break;
            }
            s = start_min, e = end_max;
        }
        if(s >= h[n-1] + k || e <= h[n-1]) ans = "NO";
        cout << ans << "\n";
    }
    return 0;
}
