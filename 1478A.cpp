#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
void solve(){
    ll n;
    cin >> n;
    ll cnt[101] = {0};
    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    for(ll i = 0; i < 101; i++){
        ans = max(ans, cnt[i]);
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
