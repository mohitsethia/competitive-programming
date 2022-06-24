#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
ll fast_exp(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp&1){
            (res *= base) %= mod;
        }
        (base *= base) %= mod;
        exp >>= 1;
    }
    return res%mod;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans;
        if(n < 3){
            ans = n;
        }
        else if(n%3 == 1){
            ll np = (n-4)/3;
            ans = 4*fast_exp(3, np);
        }
        else if(n%3 == 2){
            ll np = (n-2)/3;
            ans = 2*fast_exp(3, np);
        }
        else{
            ans = fast_exp(3, n/3);
        }
        cout << ans%mod << endl;
    }
    return 0;
}
