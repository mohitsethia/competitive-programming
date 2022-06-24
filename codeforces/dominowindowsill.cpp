#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
void solve(){
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if((k1+k2)/2 >= w && (2*n-k1-k2)/2 >= b){
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
