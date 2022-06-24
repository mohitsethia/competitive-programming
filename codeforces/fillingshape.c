#include<stdio.h>
int main(){
    int n, i, j, ans = 1;
    scanf("%d", &n);
    if(n % 2 == 0){
        i = n / 2;
        for(j = 1; j <= i; j++)
            ans = 2 * ans;
        printf("%d", ans);
    }
    else
        printf("0");
    return 0;
}
