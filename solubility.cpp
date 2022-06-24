#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, a, b;
        cin >> x >> a >> b;
        int ans = (a*10) + ((100-x)*(b*10));
        cout << ans << endl;
    }
    return 0;
}
