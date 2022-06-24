#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;
#define int long long

int32_t main(){
    int p, d;
    cin >> p >> d;
    int n = ++p;
    for(int k = 10;; k *= 10){
        if(p%k > d){
            break;
        }
        n = p - (p%k);
    }
    cout << n-1 << "\n";
    return 0;
}
