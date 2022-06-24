#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
bool find(ll n, ll d){
    while(n){
        if(n%10 == d) return true;
        n /= 10;
    }
    return false;
}
void solve(){
    ll n, d;
    cin >> n >> d;
    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        if(d == 1){
            cout << "YES\n";
            continue;
        }
        if(x%d == 0 || find(x, d)){
            cout << "YES\n";
            continue;
        }
        bool res = false;
        for(ll k = 0; k < 101; k++){
            if(find(x, d)){
                res = true;
                break;
            }
            x -= d;
        }
        if(x == 0) res = true;
        if(res) cout << "YES\n";
        else cout << "NO\n";
    }
    return;
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
