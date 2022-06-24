#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int x = x2 - x1;
        int y = y2 - y1;
        bool f = false;
        if(x == 0){
            if(y > 0){
                cout << "up\n";
            }
            else{
                cout << "down\n";
            }
            f = true;
        }
        else if(y == 0){
            if(x > 0){
                cout << "right\n";
            }
            else{
                cout << "left\n";
            }
            f = true;
        }
        if(!f){
            cout << "sad\n";
        }
    }
    return 0;
}
