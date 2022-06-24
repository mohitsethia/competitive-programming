#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        if(2*l > r){
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " " << 2*l << endl;
    }
    return 0;
}
