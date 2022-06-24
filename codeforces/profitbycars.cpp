#include<iostream>
using namespace std;
#define int long long
bool mycompare(int x, int y){
    return x < y;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        n--;
        while(n>=0 && a[n] > 0){
            ans += a[n];
//            cout << ans << " ";
            n--;
        }
        cout << ans << endl;
    }
    return 0;
}
