#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, i = 1, k = 1;
        cin >> n;
        if(n > 0){
            cout << "O";
        }
        else{
            cout << "X";
        }
        while(--n && n > 0){
            cout << ".";
            i++;
            if(i == 8){
                i = 0;
                k++;
                cout << endl;
            }
        }
        for(int l = k; l <= 8; l++){
            for(int j = i; j < 8; j++){
                cout << "X";
            }
            i = 0;
            cout << endl;
        }
    }
    return 0;
}
