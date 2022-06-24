#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = n/3;
        ll mx = (max(n-ans, ans)+1)/2;
        if(mx*2 + ans == n){
            cout << ans << " " << mx << "\n";
        }
        else{
            cout << mx << " " << ans << "\n";
        }
    }
    return 0;
}
