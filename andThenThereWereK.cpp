#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    int n;
    cin >> n;
    int base = 1;
    while(base <= n){
        base *= 2;
    }
    base /= 2;
    cout << base -1 << endl;
    }
    return 0;
}
