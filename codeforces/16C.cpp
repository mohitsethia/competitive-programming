#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int g = gcd(x, y);
    x /= g;
    y /= g;
    if(n < x || m < y){
        cout << "0 0\n";
        return 0;
    }
    int k = min(n/x, m/y);
    cout << x*k << " " << y*k << "\n";
    return 0;
}
