#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int p[1000][1000] = {0};
void per(int n, int r){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(i, r); j++){
            if(j == 0){
                p[i][j] = 1;
            }
            else{
                p[i][j] = p[i-1][j] + (j*p[i-1][j-1]);
            }       
        }
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;
        if(p[n][r] == 0){
            per(n,r);
        }
        cout << p[n][r] << endl;    
    }
    return 0;
}
