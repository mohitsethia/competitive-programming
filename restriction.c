#include<stdio.h>

int main(){
    int n, h, m;
    scanf("%d%d%d", &n, &h, &m);
    int l, r, x, i, j, a[n], total = 0;
    for(i = 0; i < n; i++)
        a[i] = h;
    for(i = 0; i < m; i++){
        scanf("%d%d%d", &l, & r, &x);
        for(j = l-1; j < r; j++){
            if(a[j] >= x)
                a[j] = x;
        }
    }
    for(i = 0; i < n; i++)
        total += a[i]*a[i];
    printf("%d\n", total);
    return 0;
}
