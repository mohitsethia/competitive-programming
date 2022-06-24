#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a1, a2, b1, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 == a2){
            if(a1 == b1 + b2){
                cout << "YES" << endl;
                continue;
            }
        }
        if(a1 == b2){
            if(a1 == a2 + b1){
                cout << "YES" << endl;
                continue;
            }
        }
        if(b1 == a2){
            if(b1 == a1 + b2){
                cout << "YES" << endl;
                continue;
            }
        }
        if(b1 == b2){
            if(b1 == a1 + a2){
                cout << "YES" << endl;
                continue;
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}
