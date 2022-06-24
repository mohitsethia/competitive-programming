#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x, f = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x < 0) f = 1;
        }
        if(f){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            cout << "101\n";
            for(int i = 0; i <= 100; i++){
                cout << i << " \n"[i == 100];
            }
        }
    }
    return 0;
}
