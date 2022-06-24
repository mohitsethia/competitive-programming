#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    scanf("%lld", &t);
    while(t--){
        int n;
        scanf("%lld", &n);
        int a[n], mn = INT_MAX;
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            mn = min(mn, a[i]);
        }
        int cnt = 0, flag = 1, ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == mn) cnt++;
            if((a[i]&mn) != mn){
                flag = 0;
                break;
            }
        }
        cnt = cnt*(cnt-1);
        if(flag){
            for(int i = 2; i < n-1; i++){
                cnt = (cnt*i)%mod;
            }
            ans = cnt;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
