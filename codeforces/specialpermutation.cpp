#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 3){
            cout << "-1" << endl;   
            continue;
        }
        int x, y;
        if(n%2 == 0){
            x = n - 1;
            y = 2;
        }
        else{
            x = n;
        }
        while(x > 0){
            cout << x << " ";
            x -= 2;
        }
        y = 6;
        cout << "4" << " 2 ";
        while(y <= n){
            cout << y << " ";
            y += 2;
        }
        cout << endl;
    }
    return 0;
}
