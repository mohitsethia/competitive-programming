#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, d = 2, s = 0, i = 0;
        cin >> n;
        while(n > 1){
            while(d + i <= n){
                if(i + d <= n){
                    i += d;
                }
                d += 3;
            }
            s++;
            n = n - i;
            i = 0;
            d = 2;
        }
        cout << s << endl;
    }
    return 0;
}
