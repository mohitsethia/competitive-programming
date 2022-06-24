#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
void solve(){
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        if(a[i] < k) a[i] = 0;
        else if(a[i] > k) a[i] = 2;
        else a[i] = 1;
    }
    if(mp.find(k) == mp.end()){
        cout << "no\n";
    }
    else{
        if(mp[k] == n){
            cout << "yes\n";
        }
        else{
            for(ll i = 0; i < n; i++){
                for(ll j = i+1; j < n && j-i <= 2; j++){
                    if(a[i] && a[j]){
                        cout << "yes\n";
                        return;
                    }
                }
            }
            cout << "no\n";
            return;
        }
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
