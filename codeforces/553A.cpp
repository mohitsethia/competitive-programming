#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
#include<iomanip>
using namespace std;
using ll = long long;
const ll mod = (ll)1e9 + 7ll;
const ll maxn = 1010;
ll nCr[maxn][maxn];
void precompute(){
    nCr[0][0] = 1;
    for(ll i = 1; i < maxn; i++){
        nCr[i][0] = nCr[i][i] = 1;
        for(ll j = 1; j < i; j++){
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) % mod;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    precompute();
    ll n;
    cin >> n;
    ll balls;
    ll total_balls = 0ll;
    ll res = 1ll;
    for(ll i = 0; i < n; i++){
        cin >> balls;
        total_balls += balls;
        res *= nCr[total_balls-1][balls-1];
        res %= mod;
    }
    cout << res%mod << "\n";
    return 0;
}
