#include<stdio.h>
int main(){
    long long int t;
    scanf("%lld", &t);
    while(t--){
        long long int n, k, count = 0, m;
        scanf("%lld%lld", &n, &k);
        if(k == 1)
            printf("NO\n");
        else{
            while(n >= k){
                n -= k;
                count++;
            }
            if(count == k)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
