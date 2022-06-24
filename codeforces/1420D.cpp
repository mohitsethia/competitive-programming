#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

#define mp make_pair

const ll MOD = 998'244'353;
const ll N = 3e5+2;

ll fact[N];

ll fast_exp(ll base, ll exp, ll mod){
    ll res = 1ll;
    while(exp){
        if(exp&1){
            res = (res * base) %mod;
        }
        (base *= base) %= mod;
        exp >>= 1;
    }
    return res;
}

void factorial(){
    fact[0] = fact[1] = 1;
    for(ll i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

ll nCr(ll n, ll r){
    if(r == 0){
        return 1ll;
    }
    return (fact[n]*fast_exp(fact[r], MOD-2, MOD)%MOD * fast_exp(fact[n-r], MOD-2, MOD) % MOD) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    factorial();
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll> > points;
    ll l, r;
    for(ll i = 0; i < n; i++){
        cin >> l >> r;
        points.emplace_back(mp(l, 0));
        points.emplace_back(mp(r, 1));
    }
    sort(points.begin(), points.end());
    ll now = 0, ans = 0;
    for(ll i = 0; i < (ll)points.size(); i++){
        if(points[i].second == 0){
            if(now >= k-1){
                ans += nCr(now, k-1);
                ans %= MOD;
            }
            now++;
        }
        else{
            now--;
        }
    }
    cout << ans << "\n";
    return 0;
}
