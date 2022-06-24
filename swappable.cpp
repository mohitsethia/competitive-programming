#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(auto &it: mp){
        ll x = it.second;
        ans += x*(x-1)/2;
    }
    ll tot = n*(n-1)/2;
    cout << tot-ans << endl;
    return 0;
}

