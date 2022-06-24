#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
using ll = long long;
const ll N = 1e7+2;
vector<ll> prime(N);
void sieve(){
    prime[1] = 1;
    for(ll i = 2; i < N; i++){
        prime[i] = (i%2 ? i : 2);
    }
    for(ll i = 3; i*i < N; i++){
        if(prime[i] == i){
            for(ll j = i*i; j < N; j += i){
                if(prime[j] == j){
                    prime[j] = i;
                }
            }
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
        ll n, k;
        cin >> n >> k;
        ll x;
        ll cnt = 1;
        set<ll> s;
        for(ll i = 0; i < n; i++){
            cin >> x;
            ll times = 0, now = 1;
            while(x > 1){
                ll d = prime[x];
                times = 0;
                while(x%d == 0){
                    times++;
                    x /= d;
                }
                if(times&1){
                    now *= d;
                }
            }
            if(s.find(now) != s.end()){
                cnt++;
                s.clear();
            }
            s.insert(now);
        }
        cout << cnt << "\n";
    }
    return 0;
}
