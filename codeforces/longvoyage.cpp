#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x = (n+3)/4;
        for(int i = 0; i < n-x; i++){
            cout << "9";
        }
        for(int i = 0; i < x; i++){
            cout << "8";
        }
        cout << endl;
    }
    return 0;
}
