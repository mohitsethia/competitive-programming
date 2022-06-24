#include<iostream>
using namespace std;
int func(int n){
    n = n + 1;
    cout << "Address inside function" << &n << endl;
    return n;
}
int main(){
    int n;
    cin >> n;
    int ans = func(n);
    cout << "Address in main" << &n << endl;
    cout << "Value in main" << n << endl << "Value in function" << ans << endl;
    return 0;
}
