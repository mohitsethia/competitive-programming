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
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0, curr = 1;
        for(ll i = 0; i < n; i++){
            if(curr++ == a[i]){
                ans++;
                curr = 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
