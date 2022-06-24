#include<stdio.h>
int main(){
    int n, count = 0;
    scanf("%d", &n);
    int a[n], h[n], i, j;
    for(i = 0; i < n; i++)
        scanf("%d%d", &a[i], &h[i]);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[j] == h[i] && i != j)
                count++;
}
}
    printf("%d", count);
    return 0;
}
