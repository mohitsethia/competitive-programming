#include<stdio.h>

int main(){
    unsigned long long int n, m, a;
    scanf("%llu%llu%llu", &n, &m, &a);
    printf("%llu\n", ((n+a-1)/a) * ((m+a-1)/a));
    return 0;
}
