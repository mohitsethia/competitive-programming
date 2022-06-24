#include<stdio.h>
int main(){
    long long int n;
    scanf("%lld", &n);
    while(n--){
        long long int a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", (a+b+c)/2);
    }
    return 0;
}
