#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int d;
        cin >> d;
        cout << d%9+1 << endl;
    }
    return 0;
}
