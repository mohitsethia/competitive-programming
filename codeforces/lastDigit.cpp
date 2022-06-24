#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
const int mod = 1e18+1;
int power(int base, int e){
    int ans = 1;
    if(e == 0){
        return ans;
    }
    if(e == 1){
        return base%10;
    }
    while(e){
        if(e&1){
            ans *= base;
        }
        (base *= base) %= 10;
        ans %= 10;
        e /= 2;
        if(ans == 0){
            break;
        }
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        cout << power(a, b) << endl;
    }
    return 0;
}
