#include<stdio.h>
int main(){
    unsigned long long int n, k;
    scanf("%llu%llu",&n, &k); 
    if(k <= (n+1) / 2)
        printf("%llu", k*2 - 1);
    else
        printf("%llu", (k - ((n+1)/2)) * 2);
    return 0;
}
