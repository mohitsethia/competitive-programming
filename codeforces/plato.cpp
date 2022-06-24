#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int n, ans = 0;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        ans += x;
    }
    cout << ans*ans << endl;
    return 0;
}
