#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<math.h>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    double discriminant = b*b - 4*a*c;
    double mx = (-b + sqrt(discriminant))/((2.0)*a);
    double mn = (-b - sqrt(discriminant))/((2.0)*a);
    if(mx < mn){
        swap(mx, mn);
    }
    cout << fixed << setprecision(15) << mx << '\n' << mn << endl;
    return 0;
}
