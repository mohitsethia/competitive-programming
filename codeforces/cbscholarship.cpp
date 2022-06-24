#include<iostream>
using namespace std;
#define ll long long int
ll findmaxstudents(ll n, ll m, ll x, ll y){
    ll s = 0, e = n, ans = 0;
    while(s <= e){
        ll mid = (s+e)/2;
        ll coupons = (n - mid)*y;
        if((m+coupons) >= (mid*x)){
            ans = max(ans, mid); 
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}
int main(){
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll ans = findmaxstudents(n, m, x, y);
    cout << ans << endl;
    return 0;
}
