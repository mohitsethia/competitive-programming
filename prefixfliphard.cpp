#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;

void solve(){
    ll n;
    string a, b;
    cin >> n >> a >> b;
    vector<ll> v, c;
    for(ll i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            v.emplace_back(i);
        }
    }
    if(a[n-1] != b[n-1]){
        v.emplace_back(n);
    }
    for(ll i = 1; i < n; i++){
        if(b[i] != b[i-1]){
            c.emplace_back(i);
        }
    }
    cout << (ll)v.size() + (ll)c.size() << " ";
    for(ll i = 0; i < (ll)v.size(); i++){
        cout << v[i] << " ";
    }
    for(ll j = (ll)c.size()-1; j >= 0; j--){
        cout << c[j] << " ";
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
