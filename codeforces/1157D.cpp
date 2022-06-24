#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int n, k;

signed main(){
    scanf("%lld%lld", &n, &k);
    if(k*(k+1)/2 > n){
        printf("NO\n");
    }
    else{
        int mn = 1, mx = n;
        vector<int> ans;
        for(int i = 0; i < k; i++){
            int p = min((n-(k-i)*(k-i-1)/2)/(k-i), mx);
            ans.push_back(p);
            n -= p;
            mn = p+1;
            mx = 2*p;
        }
        if(n){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for(int i = 0; i < k; i++){
                printf("%lld ", ans[i]);
            }
        }
    }
    return 0;
}
