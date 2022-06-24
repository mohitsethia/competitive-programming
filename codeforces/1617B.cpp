#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c = 1;
        n--;
        int a, b;
        if(n%2){
            a = n/2;
            b = n-a;
        }
        else{
            a = n/2;
            b = n/2;
            while(gcd(a, b) > 1){
                a++, b--;
            }
        }
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}
