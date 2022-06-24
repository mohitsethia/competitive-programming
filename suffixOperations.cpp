#include<iostream>
#include<cstdio>
#include<algorithm>
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
        ll a[n];
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = 1; i < n; i++){
            ans += abs(a[i] - a[i-1]);
        }
        ll mx = max(abs(a[0]-a[1]), abs(a[n-2]-a[n-1]));
        for(int i = 1; i < n-1; i++){
            mx = max(mx, abs(a[i-1]-a[i]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]));
        }
        cout << ans-mx << endl;
    }
    return 0;
}
