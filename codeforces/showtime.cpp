#include<iostream>
using namespace std;
int main(){
    long long int x, ans = 1;
    cin >> x;
    long long int z = x/1000;
    long long int y = x%1000;
    for(long long int i = z; i > 1; i -=2){
        (ans *= i) %= y;
    }
    ans = ans % y;
    cout << ans << endl;
    return 0;
}
