#include<iostream>
#include<algorithm>
using namespace std;
long long int powercalc(long long int a, long long int b){
    long long int ans = 1;
    long long int p = a;
    while(b != 0){
        if(b&1){
            ans *= p;
        }
        p *= p;
        b = (b >> 1);
    }
    return ans;
}
int main(){
    long long int x, y;
    cin >> x >> y;
    cout << powercalc(x, y) << endl;
    return 0;   
}
