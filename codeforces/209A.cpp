#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int MOD = 1e9+7;

int32_t main(){
    int n;
    cin >> n;
    int r = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(i%2){
            b = (r+b+1)%MOD;
            b %= MOD;
        }
        else{
            r = (r+b+1)%MOD;
            r %= MOD;
        }
    }
    cout << (r+b)%MOD << "\n";
    return 0;
}
