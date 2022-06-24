#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
void solve(){
    int n;
    cin >> n;
    int a[n], cnt = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%2){
            cnt++;
        }
    }
    if(cnt%2){
        cout << 2 << endl;
    }
    else{
        cout << 1 << endl;
    }
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
