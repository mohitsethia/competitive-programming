#include<stdio.h>
int main(){
    int n, m;
    scanf("%d", &n);
    int a[n], i, max1 = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] > max1)
            max1 = a[i];
    }
    scanf("%d", &m);
    int b[m], max2 = 0;
    for(i = 0; i < m; i++){
        scanf("%d", &b[i]);
        if(b[i] > max2)
            max2 = b[i];
    }
    printf("%d %d\n", max1, max2);
    return 0;
}
