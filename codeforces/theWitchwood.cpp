#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for(ll i = 0; i < min(n, k); i++){
        ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}
