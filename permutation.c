#include<stdio.h>
int main(){
    int n, i, count = 0;
    scanf("%d", &n);
    int a[n+1];
    if(n % 2 == 0){
        for(i = 1; i <= n; i++){
            a[i] = i;
        }
        for(i = 1; i <= n; i += 2){
            int swap = a[i];
            a[i] = a[i+1];
            a[i+1] = swap;
        }
        for(i = 1; i <= n; i++){
            printf("%d ", a[i]);
        }
    }
    else{
        printf("-1");
    }
    return 0;
}
