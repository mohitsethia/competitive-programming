#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#define endl "\n"
using namespace std;
using ll = long long;
void solve(){
    ll m, d, w;
    cin >> m >> d >> w;
    if(d == 1){
        cout << "0\n";
        return;
    }
    d--;
    ll g = gcd(d, w);
    w /= g;
    ll r = min(d+1, m);
    ll k = r/w;
    ll p = r%w;
    ll ans = w*k*(k-1)/2 + p*k;
    cout << ans << endl;
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
