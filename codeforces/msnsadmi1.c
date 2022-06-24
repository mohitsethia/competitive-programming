#include<stdio.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int a[n], b[n], c[n], i;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
            c[i] = a[i]*20;
        }
        for(i = 0; i < n; i++){
            scanf("%d", &b[i]);
            c[i] -= (b[i]*10);
        }
        int max = 0;
        for(i = 0; i < n; i++){
            if(c[i] > max)
                max = c[i];
        }
        printf("%d\n", max);
    }
    return 0;
}
