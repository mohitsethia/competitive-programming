#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int g = gcd(x, y);
    x /= g;
    y /= g;
    cout << min(a/x, b/y) << "\n";
    return 0;
}
