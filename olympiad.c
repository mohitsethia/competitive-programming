#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int min, i, a[n], f1 = 0, f2 = 0, f3 = 0, j, k;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] == 1)
            f1++;
        else if(a[i] == 2)
            f2++;
        else if(a[i] == 3)
            f3++;
    }
    if(f1 == 0 || f2 == 0 || f3 == 0)
        printf("0\n");
    else{
        min = (f1 < f2) ? (f1 < f3 ? f1 : f3) : (f2 < f3 ? f2 : f3);
        printf("%d\n", min);
        for(i = 0; i < min; ++i){
            for(j = 0, k = 1; j < n; j++){
                if(a[j] == k){
                    printf("%d ", j+1);
                    a[j] = 0;
                    k++;
                    j= -1;
                }
            }
            printf("\n");
            k = 1;
        }
    }
    return 0;
}
