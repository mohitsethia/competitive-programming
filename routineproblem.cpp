#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b*c >= a*d){
        int p = b*c - a*d;
        int q = b*c;
        int m = gcd(p, q);
        cout << p/m << "/" << q/m << endl;
    }
    else{
        int p = a*d - b*c;
        int q = a*d;
        int m = gcd(p, q);
        cout << p/m << "/" << q/m << endl;
    }
    return 0;
}
