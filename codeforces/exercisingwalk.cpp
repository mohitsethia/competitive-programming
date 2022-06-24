#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long int

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c, d, x, y, x1, y1, x2, y2, count = 0;
        cin >> a >> b >> c >> d;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        ll u = x - a + b;
        ll v = y - c + d;
		if(u>=x1 && u<=x2 && v<=y2 && v>=y1 && (x2>x1 || a+b==0)&& (y2>y1 || c+d==0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
