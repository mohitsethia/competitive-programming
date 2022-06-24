#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll mod = 998244353 ;
ll fast_exp(ll a, ll b){
    ll res = 1ll;
    while(b){
        if(b&1){
            (res *= a) %= mod;
        }
        (a *= a) %= mod;
        b >>= 1;
    }
    return res%mod;
}
ll nCr(ll n, ll r){
    ll res = 1ll;
    if(n-r < r){
        r = n-r;
    }
    for(ll i = 0; i < r; i++){
        (res *= (n-i)) %= mod;;
        res /= (i+1);
    }
    return res%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    /*
    ll res = (nCr(n-1, k)*m)%mod;
    (res *= fast_exp(m-1, k)) %= mod;
    cout << res << "\n";
    */
    vector<vector<ll> > f(n+1, vector<ll>(k+2));
    f[1][0] = m;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            (f[i+1][j] += f[i][j]) %= mod;
            (f[i+1][j+1] += f[i][j]*(m-1)) %= mod;
        }
    }
    cout << (int)f[n][k] << "\n";
    return 0;
}
