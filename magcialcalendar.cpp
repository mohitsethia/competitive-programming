#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, r, p = 0;
        cin >> n >> r;
        if(n <= 1){
            cout << 1 << endl;
            continue;
        }
        if(n <= r){
            r = n-1;
            p = 1;
        }
        int res = (r+1)*r/2 + p;
        cout << res << endl;
    }
    return 0;
}
