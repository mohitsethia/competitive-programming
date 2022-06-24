#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n;
        int isTwoPresent = 0, sum = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x == 2){
                isTwoPresent++;
            }
            sum += x;
        }
        if(!(sum%2)){
            cout << "0\n";
        }
        else if(isTwoPresent){
            cout << "1\n";
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
