#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int ans = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int d = INT_MAX;
        for(int i = 1; i < n; i++){
            d = min(d, abs(a[i]-a[i-1]));
            if(d >= a[i]){
                ans++;
            }
            else break;
        }
        cout << ans << '\n';
    }
    return 0;
}
