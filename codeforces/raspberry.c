#include<stdio.h>
int main(){
    int n, c, i, j;
    scanf("%d%d", &n, &c);
    int a[n];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int maxdiff = 0;
    for(i = 1; i < n; i++){
        if(a[i] < a[i - 1]){
            if(a[i-1] - a[i] > maxdiff)
                maxdiff = a[i-1] - a[i];
        }
    }
    j = maxdiff - c;
    if(j < 0)
        printf("0");
    else
        printf("%d", j);
    return 0;
}
