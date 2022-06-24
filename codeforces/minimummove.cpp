#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if(y > x){
            cout << "-1" << endl;
            continue;
        }
        cout << y+(x-y) << endl;
    }
    return 0;
}
