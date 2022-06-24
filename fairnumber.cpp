#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<climits>
using namespace std;
#define int int64_t
#define N 1e18+1
bool isfair(int x){
    int y = x;
    while(x){
        int d = x%10;
        if(d != 0 && y%d != 0){
            return false;
        }
        x /= 10;
    }
    return true;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, ok = 0;
        cin >> n;
        while(1){
            if(isfair(n)){
                break;
            }
            n++;
        }
        cout << n << endl;
    }
    return 0;
}
