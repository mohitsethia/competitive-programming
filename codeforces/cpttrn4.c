#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int r, c, h, w, i, j, k, l;
        scanf("%d%d%d%d", &r, &c, &h, &w);
        printf("*");
        for(i = 0; i < c; i++){
            for(j = 0; j < w; j++)
                printf("*");
            printf("*");
        }
        printf("\n");
        for(l = 0; l < r; l++){
            for(k = 0; k < h; k++){
                printf("*");
                for(i = 0; i < c; i++){
                    for(j = 0; j < w; j++)
                        printf(".");
                    printf("*");
                }
                printf("\n");
            }
            printf("*");
            for(i = 0; i < c; i++){
                for(j = 0; j < w; j++)
                    printf("*");
                printf("*");
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
