#include<stdio.h>
int main(){
    int i, n, x, y, z, sum1 = 0, sum2 = 0, sum3 = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d%d", &x, &y, &z);
        sum1 += x;
        sum2 += y;
        sum3 += z;
}
    if(sum1 == 0 && sum2 == 0 && sum3 == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
