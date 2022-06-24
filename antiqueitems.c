#include<stdio.h>
int main(){
    int n, v, k = 0, a[50] = {0}, i, j, b, count = 0;
    scanf("%d%d", &n, &v);
    for(i = 0; i < n; i++){
        scanf("%d", &k);
        for(j = 0; j < k; j++){
            scanf("%d", &b);
            if(b < v && a[i] == 0){
                a[i] = i + 1;
                count++;
            }
        }
    }
    printf("%d\n", count);
    
    for(i = 0; i < n; i++){
        if(a[i] != 0)
            printf("%d ", a[i]);
    }
    return 0;
}
