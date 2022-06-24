#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    int a = sqrt(2*n -1);
    cout << a/2 + (a&1) - 1 << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
