#include<stdio.h>
int main(){
    int n, space, i, j, k;
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(space = 1; space <= n - i; space++){
            printf(" ");
        }
        for(j = 1; j <= i; j++){
            printf("%d", j);
        }
        for(k = i - 1; k > 0; k--){
            printf("%d", k);
        }
        printf("\n");
    }
    return 0;
}
