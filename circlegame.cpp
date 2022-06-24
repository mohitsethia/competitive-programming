#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int d, k, x = 0, y = 0;
        cin >> d >> k;
        while(true){
            if(x <= y && (x+k)*(x+k)+y*y <= d*d){
                x+=k;
            }
            else if(x > y && (y+k)*(y+k)+x*x <= d*d){
                y+=k;
            }
            else{
                break;
            }
        }
        if(x == y){
            cout << "Utkarsh" << endl;
        }
        else{
            cout << "Ashish" << endl;
        }
    }
    return 0;
}
