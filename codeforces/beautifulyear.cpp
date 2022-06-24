#include<iostream>
using namespace std;
#define int long long
bool equal(int n){
    int a = n/1000;
    int b = n/100 - 10*a;
    int c = n/10 - 100*a - 10*b;
    int d = n%10;
//    cout << a << " " << b << " " << c << " " << d;
    if(a == b || b == c || c == d || d == a || d == b || c == a){
        return false;
    }
    return true;
}
int32_t main(){
    int n;
    cin >> n;
    n++;
    while(!equal(n)){
        n++;
    }
    cout << n << endl;
    return 0;
}
