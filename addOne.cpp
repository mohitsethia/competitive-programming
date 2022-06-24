#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>
#include<cstdio>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main(){
    int a[10] = {0}, b[10], ans[200010];
    a[0] = 1;
    for(int i = 0; i < 200010; i++){
        b[0] = a[9]%mod;
        b[1] = a[0]%mod + a[9]%mod;
        b[2] = a[1]%mod;
        b[3] = a[2]%mod;
        b[4] = a[3]%mod;
        b[5] = a[4]%mod;
        b[6] = a[5]%mod;
        b[7] = a[6]%mod;
        b[8] = a[7]%mod;
        b[9] = a[8]%mod;
        int s = 0;
        for(int j = 0; j <= 9; j++){
            a[j] = b[j];    
            s += b[j];
        }
        ans[i] = s%mod;
    }
    cout << endl;
    int t;
    scanf("%lld", &t);
    while(t--){
        int n, k;
        int res = 0;
        scanf("%lld%lld", &n, &k);
        while(n > 0){
            res += ans[k + n%10 - 1];
            n /= 10;
        }
        printf("%lld\n", res%mod);
    }
    return 0;
}
