#include<iostream>
#include<algorithm>
#include<climits>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, ans = 0;
        cin >> n >> k;
        int diff = abs(n-k);
        if(diff%10 > 0){
            ans++;
        }
        ans += (diff/10);
        cout << ans << endl;
    }
    return 0;
}   
