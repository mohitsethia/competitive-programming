#include<stdio.h>
int main(){
    long long int n, t, x;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld%lld", &n, &x);
        printf("%lld\n", x*2);
    }
    return 0;
}
