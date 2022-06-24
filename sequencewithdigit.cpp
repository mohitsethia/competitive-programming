#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
ll getAdd(ll x){
    int m1 = 10, m2 = 0;
    while(x > 0){
        int r = x%10;
        x /= 10;
        m1 = min(m1, r);
        m2 = max(m2, r);
    }
    return m1*m2;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, k, u, v;
        cin >> a >> k;
        k--;
        while(k--){
            ll y = getAdd(a);
            if(y == 0) break;
            a += y;
        }
        cout << a << '\n';
    }
    return 0;
}
