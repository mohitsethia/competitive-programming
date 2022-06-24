#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int res = n%9;
    if(res == 0) res = 9;
    cout << res << "\n";
    return 0;
}
