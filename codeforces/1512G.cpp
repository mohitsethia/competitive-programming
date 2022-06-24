#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
vector<ll> f(10000001);
vector<ll> g(10000001);
void sieve(){
    for(ll i = 1; i <= 10000000; i++){
        for(ll j = i; j <= 10000000; j+=i){
            f[j] += i;
        }
        if(f[i] <= 10000000 && g[f[i]] == 0){
            g[f[i]] = i;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    sieve();
    ll t;
    cin >> t;
    while(t--){
        ll c;
        cin >> c;
        if(c == 1){
            cout << "1\n";
            continue;
        }
        cout << ((g[c] == 0) ? -1 : g[c]) << "\n";
    }
    return 0;
}
