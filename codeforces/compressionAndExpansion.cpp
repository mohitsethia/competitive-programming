#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
ll prevprint(ll i, ll n, ll a[], vector<ll> &prev){
    while(i < n && prev.back() == a[i]){
        for(ll j = 0; j < (ll)prev.size(); j++){
            cout << prev[j] << '.';
        }
        cout << a[i] << "\n";
        prev.emplace_back(a[i]);
        i++;
    }
    return i;
}
void solve(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> prev;
    prev.emplace_back(1);
    cout << 1 << "\n";
    ll i = 1;
    while(i < n){
        if(prev.empty()){
            cout << a[i] << "\n";
            i++;
            prev.emplace_back(a[i]);
            continue;
        }
        if(prev.back() == a[i]){
            if(a[i] == 1)
                i = prevprint(i, n, a, prev);
            else
                prev.pop_back();
            continue;
        }
        else if(prev.back() == a[i]-1){
            prev.pop_back();
            for(ll j = 0; j < (ll)prev.size(); j++){
                cout << prev[j] << '.';
            }
            cout << a[i] << "\n";
        }
        else{
            if(a[i] == 1){
                for(ll j = 0; j < (ll)prev.size(); j++){
                    cout << prev[j] << '.';
                }
                cout << a[i] << "\n";
            }
            else{
                prev.pop_back();
                continue;
            }
        }
        prev.emplace_back(a[i]);
        i++;
    }
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
