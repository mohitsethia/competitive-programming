#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long 
using namespace std;
int32_t main(){
    int t;
    scanf("%lld", &t);
    while(t--){
        int a, y, x;
        scanf("%lld%lld%lld", &a, &y, &x);
        if(a >= y){
            printf("%lld\n", x*y);
        }
        else{
            printf("%lld\n", x*a+1);
        }
    }
    return 0;
}
