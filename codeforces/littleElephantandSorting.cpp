#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i+1] < a[i]){
            ans += a[i]-a[i+1];
        }
    }
    printf("%lld\n", ans);
    return 0;
}
