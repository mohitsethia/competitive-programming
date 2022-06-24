#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double x = 1-a/b;
    double y = 1-c/d;
    cout << (a/b)/(1-x*y) << endl;
    return 0;
}
