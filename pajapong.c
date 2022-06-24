#include<stdio.h>
int main(){
    long long T, x, y, k, l;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld%lld", &x, &y, &k);
        l = (x+y) / k;
        if(l % 2 == 0)
            printf("Chef\n");
        else
            printf("Paja\n");
    }
    return 0;
}   
