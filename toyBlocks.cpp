#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
using ll = long long;
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll mx = 0, x, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }
        ll p = ceil((sum*1.0)/(n-1));
        ll ans = max(p, mx)*(n-1) - sum;
        cout << ans << endl;
    }
    return 0;
}
