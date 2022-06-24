#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
const int mod = 100000;
ll power(ll base, ll e){
    ll res = 1;
    while(e){
        if(e&1){
            res = ((res%mod)*(base%mod))%mod;
        }
        base = (base*base)%mod;
        e >>= 1;
        res = res%mod;
        if(res == 0){
            break;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    ll n = 0;
    n = (s[0] - '0');
    n = n*10 + (s[2] - '0');
    n = n*10 + (s[4] - '0');
    n = n*10 + (s[3] - '0');
    n = n*10 + (s[1] - '0');
    ll ans = power(n, 5);
    if(ans == 0){
        cout << "00000\n";
    }
    else{
        cout << ans << endl;
    }
    return 0;
}
