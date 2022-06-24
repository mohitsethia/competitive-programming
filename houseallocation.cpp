#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    int x = 1;
    while(t--){
        int n, b;
        cin >> n >> b;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        int ans = 0, res = 0;
        for(int i = 0; i < n; i++){
            if(ans + a[i] <= b){
                ans += a[i];
                res++;
            }
            else{
                break;
            }
        }
        cout << "Case #" << x << ": " << res << endl;
        x++;
    }
    return 0;
}
