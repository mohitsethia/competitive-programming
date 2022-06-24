#include<stdio.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n], i, count = 0;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n; i++){
        if(5 - a[i] >= k)
            count++;
    }
    printf("%d", count/3);
    return 0;
}
