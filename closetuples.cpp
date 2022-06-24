#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7ll;
const ll N = 2e5+5;
ll fact[N];
ll fast_exp(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp&1){
            res = (res*base)%mod;
        }
        base = (base*base)%mod;
        exp >>= 1;
    }
    return res;
}
ll nCr(ll n, ll r){
    if(r > n) return 0;
    if(n < 0 || r < 0){
        return 0;
    }
    if(r == 0){
        return 1;
    }
    return (fact[n]*fast_exp(fact[r], mod-2) % mod * fast_exp(fact[n-r], mod-2) % mod) % mod;
}
int32_t main(){
    int t;
    cin >> t;
    fact[0] = 1;
    fact[1] = 1;
    for(ll i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> a(n);
        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll l = 0, r = 0;
        ll ans = 0;
        for(r = 0; r < n; r++){
            while(a[r]-a[l] > k){
                l++;
            }
            ans += nCr(r-l, m-1);
            ans %= mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
