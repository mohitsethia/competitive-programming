#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && a[i] == -1 && a[i-1] != -1){
                mn = min(mn, a[i-1]), mx = max(mx, a[i-1]);
            }
        }
        for(int i = 0; i < n; i++){
            if(i < n-1 && a[i] == -1 && a[i+1] != -1){
                mn = min(mn, a[i+1]), mx = max(mx, a[i+1]);
            }
        }
        int res = (mx+mn)/2, ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == -1) a[i] = res;
            if(i > 0) ans = max(ans, abs(a[i]-a[i-1]));
        }
        cout << ans << " " << res << endl;
    }
    return 0;
}
