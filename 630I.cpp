#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int power(int x, int e){
    int res = 1;
    while(e){
        if(e&1){
            res *= x;
        }
        e /= 2;
        x *= x;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int extremeLeftPlusRight = 2* (4 * 3 * power(4, 2*n-2-n-1));
    int middle = 4*3*3*power(4, 2*n-2-n-2)*(n-3);
    int ans = extremeLeftPlusRight + middle;
    cout << ans << endl;
    return 0;
}
