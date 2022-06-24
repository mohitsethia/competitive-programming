#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int int64_t
int32_t main(){
    int n;
    cin >> n;
    while(n--){
        int a, i = 2;
        cin >> a;
        if(a <= 3){
            cout << "NO" << endl;
            continue;
        }
        int b = sqrt(a);
        for(i = 2; i*i <= b; i++){
            if(b%i == 0){
                break;
            }
        }
        if(b*b == a && i*i > b && a > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
