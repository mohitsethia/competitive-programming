#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
bool check(ll x, ll y, ll a, ll b, ll n){
    ll low = 0, high = n;
    while(low <= high){
        ll mid = (low+high)/2;
        ll s1 = mid;
        ll s2 = n-mid;
        ll t1 = a*s1 + b*s2;
        ll t2 = b*s1 + a*s2;
        if(t1 <= x && t2 <= y){
            return true;
        }
        if(t1 > x){
            if(a > b){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(a > b){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
}
void solve(){
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    ll ans = 0;
    ll high = 1e9, low = 0;
    while(low <= high){
        ll mid = (low+high)/2;
        if(check(x, y, a, b, mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << "\n";
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
