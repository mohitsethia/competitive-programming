#include<stdio.h>
int main(){
    int n, r, c, i, j;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &r, &c);
        for(i = 0; i < r; i++){
            if(i%2 == 0){
                for(j = 0; j < c; j++){
                    if(j%2 == 0)
                        printf("*");
                    else
                        printf(".");
                }
            }
            else{
                for(j = 0; j < c; j++){
                    if(j%2 == 0)
                        printf(".");
                    else
                        printf("*");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
