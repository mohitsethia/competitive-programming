#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll a, b, c, d, ans = 0;
        cin >> a >> b >> c >> d;
        if(a <= b){
            cout << b << endl;
            continue;
        }
        else if(a > b && c > d){
            ans += b;
            a -= b;
            if(a % (c-d) != 0){
                a /= (c-d);
                ans += (a+1)*c;
            }
            else{
                a /= (c-d);
                ans += a*c;
            }
            cout << ans << endl;
            continue;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
