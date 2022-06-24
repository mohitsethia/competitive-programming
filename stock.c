#include<stdio.h>
int main(){
    int m, n, r, x, y, i, j, k, l1, l2, p;
    scanf("%d%d%d", &n, &m, &r);
    int a[n], b[m];
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(j = 0; j < m; j++)
        scanf("%d", &b[j]);
    x = a[0];
    y = b[0];
    for(i = 0; i < n; i++){
        if(a[i] < x)
            x = a[i];
    }
    k = r / x;
    l1 = k * x;
    p = r - l1;
    for(j = 0; j < m; j++){
        if(b[j] > y)
            y = b[j];
    }
    l2 = k * y;
    if(l2 < l1)
        printf("%d", r);
    else
        printf("%d", l2 + p);
    return 0;
}
