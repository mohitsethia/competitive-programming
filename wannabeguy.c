#include<stdio.h>
int main(){
    int n, x, y, i, j, k, count = 0;
    scanf("%d", &n);
    scanf("%d", &x);
    int a[x];
    for(i = 0; i < x; i++)
        scanf("%d", &a[i]);
    scanf("%d", &y);
    int b[y];
    for(j = 0; j < y; j++)
        scanf("%d", &b[j]);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= x || j <= y; j++){
            if(j <= x){
                if(i == a[j]){
                count++;
                break;
            }       
        }
            if(j <= y){
                if(i == b[j]){
                    count++;
                    break;
                }
            }
        }
    }
        if(count == n)
            printf("I become the guy.\n");
        else
            printf("Oh, my keyboard!\n");
    return 0;
}
