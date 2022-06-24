#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int ans = to_string(b+1).length()-1;
        ans *= a;
        cout << ans << "\n";
    }
    return 0;
}
