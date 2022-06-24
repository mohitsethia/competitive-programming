#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 1; 
    for(int i = 0; i < b; i++){
        ans *= (a%c);
    }
    ans = ans%c;
    cout << ans << endl;
    return 0;
}   
