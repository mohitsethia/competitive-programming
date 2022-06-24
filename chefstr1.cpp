#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a, ans = 0;
        cin >> a;
        for(int i = 1; i < n; i++){
            int b;
            cin >> b;
            ans += (abs(b-a)-1);
            a = b;
        }
        cout << ans << endl;
    }
    return 0;
}
