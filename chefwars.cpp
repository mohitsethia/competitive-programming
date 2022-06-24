#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int h, p;
        cin >> h >> p;
        bool d = true, c = true;
        while(h > 0 && p > 0){
            h -= p;
            p /= 2;
//            cout << h << " " << p << endl;
            if(p == 0){
                c = false;
                break;
            }
            if(h <= 0){
                d = false;
            }
        }
        if(d){
            cout << "0" << endl;
        }
        else{
            cout << "1" << endl;
        }
    }
    return 0;
}
