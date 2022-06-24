#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, h;
    cin >> r >> h;
    int ans = h/r*2;
    h = h%r;
    if(2*h < r) ans++;
    else if(2*h >= sqrt(3)*r) ans += 3;
    else ans += 2;
    cout << ans << "\n";
    return 0;
}
