#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if(n == 1 && m == 1){
        cout << min(x, y) << endl;
        return;
    }
    if(n*m > 1){
        x = min(x, y);
    }
    y = min(y, 2*x);
    cout << (n*m + 1)/2*x + (n*m)/2*(y-x) << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
