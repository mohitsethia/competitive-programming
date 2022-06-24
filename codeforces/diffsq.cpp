#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int l, r, count = 0;
        cin >> l >> r;
        int x = l;
        for(int i = x; i < 5; i++){
            if(i%4 == 2){
                x = i;
                break;
            }
        }
        for(int i = x; i <= r; i+=4){
            count++;
        }
        int ans = (r-l+1) - count;
        cout << ans << endl;
    }
    return 0;
}
