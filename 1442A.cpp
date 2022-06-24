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
        vector<ll> a(n+1);
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll mx = a[n];
        bool ok = true;
        for(ll i = n; i > 1; i--){
            if(a[i] > a[i-1]){
                if(a[i]-a[i-1] <= mx){
                    mx = mx-(a[i]-a[i-1]);
                }
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
