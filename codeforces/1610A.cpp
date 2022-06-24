#include<iostream>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a == 1 && b == 1){
            cout << "0\n";
        }
        else if(a == 1 || b == 1){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}
