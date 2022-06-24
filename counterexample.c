#include<stdio.h>
int main(){
    long long int l, r;
    scanf("%lld%lld", &l, &r);
    if(l + 2 > r){
        printf("-1\n");
        return 0;
    }
    if(l % 2 == 0){
        printf("%lld %lld %lld\n", l, l + 1, l + 2);
        return 0;
    }
    if(l + 2 < r){
        printf("%lld %lld %lld\n", l + 1, l + 2, l + 3);
        return 0;
    }
    printf("-1\n");
}
