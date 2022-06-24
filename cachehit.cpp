#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, b, m;
        cin >> n >> b >> m;
        int ans = 0, count = -1;
        for(int i = 0; i < m; i++){
            int fn;
            cin >> fn;
            if(count == -1){
                count = fn/b;
                ans++;
                continue;
            }
            if(fn/b != count){
                count = fn/b;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
