#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ff = 0;
        for(int i = 0; i < n-1; i++){
            int x = 0;
            for(int j = 0; j <= i; j++){
                x ^= a[j];
            }
            int temp = 0, f = 0;
            for(int j = i+1; j < n; j++){
                temp ^= a[j];
                if(temp == x){
                    temp = 0;
                    f = 1;
                }
            }
            if(temp == 0 && f){
                cout << "YES" << endl;
                ff = 1;
                break;
            }
        }
        if(!ff){
            cout << "NO" << endl;
        }
    }
    return 0;
}
