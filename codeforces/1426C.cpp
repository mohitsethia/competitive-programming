#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 1e9 + 7;
        for(int i = 1; i*i <= n; i++){
            int moves = (i-1); // to increase
            moves += ((n-i)+i-1)/i; // to copy
            ans = min(ans, moves);
        }
        cout << ans << "\n";
    }
    return 0;
}
