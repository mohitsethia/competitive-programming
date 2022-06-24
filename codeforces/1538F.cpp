#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        ll ans = 0ll;
        while(l || r){
            ans += r-l;
            r /= 10;
            l /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}
