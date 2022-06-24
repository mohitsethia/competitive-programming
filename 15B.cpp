#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, x0, x1, y0, y1;
        cin >> n >> m >> x0 >> y0 >> x1 >> y1;
        int x = abs(x0-x1);
        int y = abs(y0-y1);
        int ans = (n-x)*(m-y)*2;
        if(n-2*x > 0 && m-2*y > 0){
            ans -= (n-2*x)*(m-2*y);
        }
        ans = (n*m)-ans;
        cout << ans << "\n";
    }
    return 0;
}
