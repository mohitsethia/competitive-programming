#include<iostream>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << (a+b+c-1) << "\n";
    }
    return 0;
}
