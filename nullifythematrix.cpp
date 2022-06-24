#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n+1][m+1], xorsum[n+m+1];
        memset(xorsum, 0, sizeof(xorsum));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
                xorsum[i+j] ^= a[i][j];
            }
        }
        int flag = 1;
        for(int i = 1; i <= n+m; i++){
            flag &= (xorsum[i] == 0);
        }
        if(!flag){
            cout << "Ashish" << endl;
        }
        else{
            cout << "Jeel" << endl;
        }
    }
    return 0;
}   
