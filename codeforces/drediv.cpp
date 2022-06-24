#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve(){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int x = a[i];
        while(1){
            if(x%k == 0){
                break;
            }
            if(x > 20000000000){
                cout << "NO\n";
                return;
            }
            x *= 2;
        }
    }
    cout << "YES\n";
    return;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
