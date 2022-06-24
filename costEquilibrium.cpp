#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;
const ll MAXN = 2e5 + 1;
ll fast_exp(ll base, ll exp, ll mod){
    ll res = 1;
    while(exp){
        if(exp&1){
            res = (res * base)%mod;
        }
        base = (base * base)%mod;
        exp >>= 1;
    }
    return res;
}

ll fact[MAXN];
ll inv[MAXN];

void factorial(){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < MAXN; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    inv[MAXN-1] = fast_exp(fact[MAXN-1], mod-2, mod);
    for(ll i = MAXN-2; i >= 0; i--){
        inv[i] = (inv[i+1] * (i+1)) % mod;
    }
}

ll nCr(ll n, ll r){
    if(r > n || r < 0){
        return 0;
    }
    ll res = fact[n];
    res *= (inv[r] * inv[n-r])%mod;
    res %= mod;
    return res;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    factorial();
    ll p = 0ll;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        p += a[i];
    }
    if(p%n != 0){
        cout << 0;
        return 0;
    }
    ll avg = p/n;
    map<ll, ll> freqSrc, freqSnk;
    ll src = 0, snk = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] > avg){
            src++;
            freqSrc[a[i]]++;
        }
        if(a[i] < avg){
            snk++;
            freqSnk[a[i]]++;
        }
    }
    if(src == 0 && snk == 0){
        cout << 1;
        return 0;
    }
    if(src == 1 || snk == 1){
        ll ans = fact[n];
        for(auto it: freqSnk){
            ans = (ans * inv[it.second]) %mod;
        }
        for(auto it: freqSrc){
            ans = (ans * inv[it.second]) % mod;
        }
        ans = (ans * inv[n-src-snk]) % mod;
        cout << ans;
        return 0;
    }
    ll ans = (2ll * fact[src] * fact[snk]) % mod;
    for(auto it: freqSrc){
        ans = (ans * inv[it.second]) % mod;
    }
    for(auto it: freqSnk){
        ans = (ans * inv[it.second]) % mod;
    }
    ll left = n-src-snk;
    ans = (ans * nCr(left + src + snk, src+snk)) % mod;
    cout << ans;
    return 0;
}
