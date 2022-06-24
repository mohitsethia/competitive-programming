#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

#define int long long

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int32_t main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    int g = gcd(a, b, x, y);
    if(c%g){
        cout << "-1\n";
    }
    else{
        cout << -c/g*x << " " << -c/g*y << "\n";
    }
    return 0;
}
