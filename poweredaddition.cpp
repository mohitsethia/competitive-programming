#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[n];
        for(int i = 0; i < n; i++){ 
            cin >> a[i];
        }
        long long ans = 0ll;
        for(int i = 1; i < n; i++){
            long long diff = a[i]-a[i-1];
            if(diff >= 0) continue;
            diff *= -1ll;
            long long base = 1ll, cnt = 1ll;
            while(2ll*base <= diff){
                base *= 2ll;
                cnt++;
            }
            ans = max(ans, cnt);
            a[i] = a[i-1];
        }
        cout << ans << "\n";
    }
    return 0;   
}
