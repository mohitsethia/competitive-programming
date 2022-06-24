#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, n, count = 0;
        cin >> a >> b >> n;
        while(a <= n && b <= n){
            if(a < b){
                a += b;
            }
            else{
                b += a;
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
