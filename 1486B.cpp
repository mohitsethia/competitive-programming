#include<iostream>
#include<algorithm>
#include<vector>

#define int long long 
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> x(n), y(n);
        for(int i = 0; i < n; i++){
            cin >> x[i] >> y[i];
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        int ans = 1;
        if(n%2 == 0){
            ans = (x[n/2]-x[n/2-1] + 1) * (y[n/2] - y[n/2-1] +1);
        }
        cout << ans << "\n";
    }
    return 0;
}
