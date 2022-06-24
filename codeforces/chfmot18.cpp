#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int s, n, ans = 0;
        cin >> s >> n;
        if(s <= n){
            if(s == 1){
                ans = 1;
            }
            else if(s&1){
                ans = 2;
            }
            else{
                ans = 1;
            }
        }
        else{
            if(s&1){
                ans++;
                s--;
            }
            if(s%n == 0){
                ans += (s/n);
            }
            else{
                ans += (s/n);
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
