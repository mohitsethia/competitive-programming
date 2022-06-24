#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    if(k == 1){
        cout << a*(n-1) << endl;
        return 0;
    }
    ll ans = 0;
    while(n != 1){
        if(n < k){
            ans += a*(n-1);
            break;
        }
        if(n%k != 0){
            ans += a*(n%k);
            n = n/k*k;
        }
        ans += min(b, (n-n/k)*a);
        n /= k;
    }
    cout << ans << endl;
    return 0;
}
