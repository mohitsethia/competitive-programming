#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < c){
            cout << "1 ";
        }
        else{
            cout << "-1 ";
        }
        if(b*a > c){
            cout << b << endl;
        }
        else{
            cout << "-1 " << endl;
        }
    }
    return 0;
}
