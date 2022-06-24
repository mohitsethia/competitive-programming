#include<stdio.h>
#include<math.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], b[m], i, count = 0, flag = 0, j;
    int  even1 = 0, even2 = 0, odd1 = 0, odd2 = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(a[i] % 2 == 0)
            even1++;
        else
            odd1++;
}
    for(j = 0; j < m; j++){
        scanf("%d", &b[j]);
        if(b[j] % 2 == 0)
            even2++;
        else
            odd2++;
}
    if(even1 <= odd2)
        count = even1;
    else
        count = odd2;
    if(even2 <= odd1)
        flag = even2;
    else
        flag = odd1;

        printf("%d\n", count + flag);
    return 0;
}
