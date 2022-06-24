#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x > 45){
            cout << "-1" << endl;
            continue;
        }
        int res = 0, i = 9, ans = 0;
        while(x > 0 && i > 0){
            if(x - i >= 0){
                x -= i;
                res = res*10 + i;
            }
            i--;
        }
        while(res){
            ans = ans*10 + res%10;
            res /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}
