#include<iostream>
#include<algorithm>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
ll mod(ll n){
    if(n < 0){
        n += MOD;
    }
    return n%MOD;
}
ll fast_exp(int base, int exp){
    ll res = 1ll;
    while(exp){
        if(exp&1){
            res = mod((res*base));
        }
        base = mod((base*base));
        exp/=2;
    }
    return mod(res);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll ans = 1;
        for(int i = 1; i <= k; i++){
            (ans *= n) %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
