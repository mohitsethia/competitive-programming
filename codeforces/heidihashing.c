#include<stdio.h>
int main(){
    long long int r, x = 1, y;
    scanf("%lld", &r);
    if(r % 2 == 0 || r < 5)
        printf("NO\n");
    else{
        y = (r - 3) / 2;
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
