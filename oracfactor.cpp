#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define ll long long int
bool isPrime(ll x){
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    ll t;
    cin >>t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        if(n%2 == 0){
            //n is even and its smallest divisor will always be 2
            cout << n + 2*k << endl;
        }
        else{
            //n is odd so its divisor will be odd for the first time and then their sum will become even and smallest divisor would be 2
            ll p;
            for(int i = 3; i <= n; i += 2){
                if(n%i == 0){
                    p = i;
                    break;
                }
            }
            cout << n + 2*(k-1) + p << endl;
        }
    }
    return 0;
}
