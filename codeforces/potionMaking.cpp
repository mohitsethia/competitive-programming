#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int x = gcd(k, 100);
        int m = 100/x;
        cout << m << endl;
    }
    return 0;
}
