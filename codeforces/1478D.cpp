#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        vector<ll> required(n), a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
            required[i] = abs(k-a[i]);
        }
        sort(a.begin(), a.end());
        ll g = 0;
        for(ll i = 1; i < n; i++){
            g = gcd(g, a[i]-a[i-1]);
        }
        bool ok = false;
        for(ll i = 0; i < n; i++){
            if(required[i]%g == 0){
                ok = true;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
