#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x % 2 == 0 && y % 2 == 0 && (x == y || y == x - 2)){
            cout << x + y << endl;
        }
        else if(x % 2 != 0 && y % 2 != 0 && (x == y || y == x - 2)){
            cout << x + y - 1 << endl;
        }
        else{
            cout << "No Number" << endl;
        }
    }
    return 0;
}
