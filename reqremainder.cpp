#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, n;
        cin >> x >> y >> n;
        int q = (n/x)*x, ans = 0;
        if(q+y > n){
            q = ((n/x) -1)*x;
            ans = q + y;
        }
        else{
            ans = q+y;
        }
        cout << ans << endl;
    }
    return 0;
}
