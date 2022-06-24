#include<stdio.h>
int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(m >= n){
        if(k >= n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    else
        printf("No\n");
    return 0;
}
