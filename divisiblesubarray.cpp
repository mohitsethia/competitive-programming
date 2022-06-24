#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int pre[n];
        memset(pre, 0, sizeof(pre));
        pre[0] = 1;
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum+n)%n;
            pre[sum]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int m = pre[i];
            ans += (m)*(m-1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}
