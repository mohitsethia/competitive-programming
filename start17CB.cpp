#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if(a == x && b == y){
            cout << "0\n";
        }
        else if(abs(a-x) == 0 || abs(b-y) == 0){
            if((a+b)%2 == (x+y)%2){
                cout << "3\n";
            }
            else{
                cout << "1\n";
            }
        }
        else{
            if((a+b)%2 == (x+y)%2){
                cout << "2\n";
            }
            else{
                cout << "3\n";
            }
        }
    }
    return 0;
}
