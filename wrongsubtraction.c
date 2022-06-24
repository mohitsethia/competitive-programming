#include<stdio.h>
int main(){
    unsigned long long n, k;
    scanf("%llu%llu", &n, &k);
    for(int i = 1; i <= k; i++){
        if(n % 10 != 0)
            n -= 1;
        else
            n /= 10;
    }
    printf("%llu", n);
    return 0;
}
