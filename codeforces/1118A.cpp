#include<iostream>
#include<algorithm>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        int ans = 0;
        if(n&1){
            ans += a;
            n--;
        }
        ans += min(n*a, n/2*b);
        cout << ans << "\n";
    }
    return 0;
}
