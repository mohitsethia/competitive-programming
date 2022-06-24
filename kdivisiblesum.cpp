#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = 0;
        if(k == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 1){
            ans = k;
        }
        else if(n > k){
            if(n%k == 0){
                ans = 1;
            }
            else{
                ans = (((n/k)*k)+k)/n + 1;
            }
        }
        else if(n < k){
            if(k%n == 0){
                ans = k/n;
            }
            else{
                ans = k/n + 1;
            }
        }
        else{
            ans = n/k;
        }
        cout << ans << endl;
    }
    return 0;
}
