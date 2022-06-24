#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef unsigned long long ll;

void solve(){
    ll n, a;
    cin >> n;
    for( a = 1; a*a*a <= n; a++){
        ll x = cbrt(n - a*a*a);
        if(x <= 0){
            cout << "NO\n";
            return;
        }
        if(x*x*x + a*a*a == n){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
