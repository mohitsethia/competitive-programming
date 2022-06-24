#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n+1);
        for(ll i = 0; i < n; i++){
            cin >> a[i+1];
        }
        sort(a.begin(), a.end());
        vector<ll> ans(n+1, (ll)1e6);
        ans[0] = 0;
        for(ll i = 1; i <= 500; i++){
            for(ll j = n; j >= 1; j--){
                ans[j] = min(ans[j], ans[j-1] + abs(i-a[j]));
            }
        }
        cout << ans[n] << "\n";
    }
    return 0;
}
