#include<stdio.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n], i, f, count = 0;
    for(i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if(i == k)
            f = a[i];
    }
    for(i = 1; i <= n; i++){
        if(a[i] > 0){
            if(a[i] >= f)
                count++;
        }
    }
    printf("%d", count);
    return 0;
}
