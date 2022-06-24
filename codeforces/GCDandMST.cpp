#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;
void solve(){
    ll n, x;
    cin >> n >> x;
    vector< ll > a(n);
    vector<pair<ll, ll > > arr(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        arr[i].first = a[i];
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    vector<bool> connect(n, false);
    ll ans = 0;
    for(ll k = 0; k < n; k++){
        ll curr_val = arr[k].first;
        ll idx = arr[k].second;
        if(curr_val >= x) break;
        while(idx > 0){
            if(connect[idx-1]) break;
            if(a[idx-1]%curr_val == 0ll){
                ans += curr_val;
                connect[idx-1] = true;
                idx--;
            }
            else break;
        }
        idx = arr[k].second;
        while(idx < n-1){
            if(connect[idx]) break;
            if(a[idx+1]%curr_val == 0ll){
                ans += curr_val;
                connect[idx] = true;
                idx++;
            }
            else break;
        }
    }
    for(ll i = 0; i < n-1; i++)
        if(!connect[i]) ans += x;
    cout << ans << "\n";
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
