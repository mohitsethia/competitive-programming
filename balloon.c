#include<stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        int a[n], i;
        for(i = 0; i < n; i++)
            scanf("%d", &a[i]);
        if(a[0] == x && a[n - 1] == y)
            printf("BOTH\n");
        if(a[0] == x && a[n - 1] != y)
            printf("EASY\n");
        if(a[0] != x && a[n - 1] == y)
            printf("HARD\n");
        if(a[0] != x && a[n - 1] != y)
            printf("OKAY\n");
}
    return 0;
}
