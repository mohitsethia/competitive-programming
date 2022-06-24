#include<stdio.h>

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    int a[n], i, sum = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    if(sum + (n-1)*10 <= d)
        printf("%d", (d - sum)/5);
    else
        printf("-1");
    return 0;
}
