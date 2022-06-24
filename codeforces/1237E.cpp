#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 5){
        cout << (n == 3 ? "0\n" : "1\n");
        return 0;
    }
    int e = 4, o = 5;
    while(e < n && o < n){
        int _o = e+e+1;
        int _e = e+o+1;
        e = _e, o = _o;
        if(e == n || o == n){
            cout << "1\n";
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}
