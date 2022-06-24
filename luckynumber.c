#include<stdio.h>
int main(){
    long long int ans = 0, n, k, i, a, c = 0;
    scanf("%lld%lld", &n, &k);
    for(i = 0; i < n; i++){
        scanf("%lld", &a);
        c = 0;
        while(a != 0){
            if(a%10 == 4 || a%10 == 7){
                c++;
            }
            a /= 10;
        }
        if(c <= k){
            ans++;
        }
    }
    printf("%lld", ans);
    return 0;
}
