#include<iostream>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        for(ll i = 2; i <= 29; i++){
            ll x = pow(2, i) - 1;
            if(n % x == 0){
                cout << n/x << endl;
                break;
            }
        }
    }
    return 0;
}
