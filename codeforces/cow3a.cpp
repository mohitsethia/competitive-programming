#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int A = (a - b + c)/2;
        int M = (a - A);
        int O = (c - A);
        cout << A << " " << M << " " << O << endl;
    }
    return 0;
}
