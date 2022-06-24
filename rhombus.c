#include<stdio.h>
int main(){
    int n, i, m = 0, ans = 0;
    scanf("%d", &n);
    for(i = 1; i < 2*n - 1; i += 2){
        m += 2*i;
    }
    ans = ((n*2) - 1) + m;
    printf("%d", ans);
    return 0;
}
