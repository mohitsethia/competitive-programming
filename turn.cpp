#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll x;
    cin >> x;
    if(x%360 == 0 || (x <= 45 && x > 0) || (x >= -45 && x < 0)){
        cout << 0 << endl;
        return 0;
    }
    ll y = x;
    if(x > 360 || x < -360){
        x /= 360;
        y = y - x*360;
    }
    ll ans = 0;
    if(y < 0){
        y += 360;
    }
    if(y <= 135 && y > 45){
        ans = 1;
    }
    else if(y > 135 && y <= 225){
        ans = 2;
    }
    else if(y > 225 && y < 315){
        ans = 3;
    }
    cout << ans << endl;
    return 0;
}
