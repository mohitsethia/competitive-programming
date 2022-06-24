#include<stdio.h>
int main(){
    int q, n;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &n);
        int a[n], i, j, count = 0, flag = 0;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(i <= 3)
            printf("YES\n");
        else{
            for(i = 1; i < n; i++){
                if(a[i] != a[i-1]+1 && a[i] != a[i-1]-1){
                    if(a[n-1] != a[0]+1 && a[n-1] != a[0]-1){
                        printf("NO\n");
                        break;
                    }
                    else{
                        if(flag == 0){
                            for(j = n-1; j > i; j--){
                                if(a[j] != a[j-1]-1 && a[j] != a[j-1]+1){
                                    printf("NO\n");
                                    flag = 1;
                                    break;
                                }
                                else
                                    count++;
                            }
                        }
                    }
                }
                else
                    count++;
            }
            if(count >= n-2)
                printf("YES\n");
        }
    }
    return 0;
}
