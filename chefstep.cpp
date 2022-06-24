#include<iostream>
#include<stdio.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        scanf("%lld%lld", &n, &k);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%lld", &x);
            if(x % k == 0){
                printf("1");
            }
            else{
                printf("0");
            }   
        }
        printf("\n");
    }
    return 0;
}
