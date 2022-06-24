#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int r, c, i, j;
        scanf("%d%d", &r, &c);
        for(i = 0; i < r; i++){
            if(i == 0 || i == r-1){
                for(j = 0; j < c; j++)
                    printf("*");
            }
            else{
                for(j = 0; j < c; j++){
                    if(j == 0 || j == c-1)
                        printf("*");
                    else
                        printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
