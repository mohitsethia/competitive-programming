#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int r, c, i, j, k;
        scanf("%d%d", &r, &c);
        printf("*");
        for(i = 0; i < c; i++)
            printf("***");
        printf("\n");
        for(k = 0; k < r; k++){
            for(j = 0; j < 2; j++){
                printf("*");
                for(i = 0; i < c; i++)
                    printf("..*");
                printf("\n");
            }
            printf("*");
            for(i = 0; i < c; i++)
                printf("***");
            printf("\n");
        }
    }
    return 0;
}
