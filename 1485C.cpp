#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for(ll k = 1; k*k <= a; k++){
            ans += max(0ll, min(b, a/k-1) - k);
        }
        cout << ans << "\n";
    }
    return 0;
}
