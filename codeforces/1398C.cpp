#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
        string s;
        cin >> n >> s;
        ll dp[n];
        map<ll, ll> mp;
        ll ans = 0;
        mp[0]++;
        for(ll i = 0; i < n; i++){
            dp[i] = (i == 0) ? (s[i]-'0') : (dp[i-1] + (s[i]-'0'));
            mp[dp[i]-i-1]++;
        }
        for(auto &it: mp){
            ans += (it.second)*(it.second -1)/2;
        }
        cout << ans << "\n";
    }
    return 0;
}
