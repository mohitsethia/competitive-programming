#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    if(x == y){
        cout << x << endl;
    }
    else{
        if(x == 0){
            if(y == 1){
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        else if(x == 1){
            if(y == 0){
                cout << 2 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
        else if(x == 2){
            if(y == 0){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
