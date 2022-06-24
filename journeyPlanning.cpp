#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll x;
    map<ll, ll> mp;
    for(int i = 1; i <= n; i++){
        cin >> x;
        mp[i-x] += x;
    }
    ll ans = 0;
    for(auto &it: mp){
        ans = max(ans, it.second);
    }
    cout << ans << endl;
    return 0;
}
