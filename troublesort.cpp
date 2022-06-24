#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n], have0 = 0, have1 = 0, sc = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];    
            if(i >= 1 && a[i] < a[i-1]){
                sc = 0;
            }
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] == 0){
                have0++;
            }
            if(b[i] == 1){
                have1++;
            }
        }
        if(have0 && have1){
            cout << "Yes" << endl;
        }
        else if(sc){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
