#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll MOD = 998'244'353;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, m, q;
        cin >> n >> m;
        ll a = 0, b = 0;
        ll x;
        for(ll i = 0; i < n; i++){
            cin >> x;
            a += x;
        }
        for(ll j = 0; j < m; j++){
            cin >> x;
            b += x;
        }
        ll l, r, type;
        cin >> q;
        while(q--){
            cin >> type;
            if(type == 1 || type == 2){
                cin >> l >> r >> x;
                ll tot = (r-l+1)*x;
                if(type == 1){
                    (a += tot) %= MOD;
                }
                else{
                    (b += tot) %= MOD;
                }
            }
            else{
                cout << ((a*b)%MOD) << "\n";
            }
        }
    }
    return 0;
}
