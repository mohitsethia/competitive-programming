#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<numeric>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<climits>

using namespace std;
using ll = long long;

#define pi pair<ll, ll>
#define vi vector<ll, ll>
#define pb push_back
#define eb emplace_back
#define vpi vector<pi>
#define mk make_pair
#define mi map<ll, ll>

const ll MOD = 1e9+ 7;

template<class T1, class T2> void add( T1 &x, T2 y, ll m = MOD ){ x += y; if( x >= m ) x -= m; }
template<class T1, class T2> void sub( T1 &x, T2 y, ll m = MOD ){ x -= y; if( x < 0 ) x += m; }
ll mod( ll n, ll m=MOD ){ n%=m;if(n<0)n+=m;return n; }

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    a /= g;
    b /= g;
    return g*a*b;
}

void solve(){
    ll n;
    cin >> n;
    ll prod = 1, ans = 0;
    for(ll i = 1; ; i++){
        if(prod > n) break;
        (ans += (n/prod) % MOD ) %= MOD;
        // add(ans, mod(n/prod));
        prod = lcm(prod, i);
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
