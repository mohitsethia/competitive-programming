#include<stdio.h>
int main(){
    int q, n, k, i, j;
    scanf("%d", &q);
    while(q--){
        scanf("%d%d", &n, &k);
        int a[n], count = 0, min, max;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        min = a[0];
        max = a[0];
        for(i = 0; i < n; i++){
            if(a[i] < min)
                min = a[i];
            if(a[i] > max)
                max = a[i];
        }
        
        if((max - min) <= 2*k)
            printf("%d\n", min+k);
        else
            printf("-1\n");
    }
    return 0;
}
