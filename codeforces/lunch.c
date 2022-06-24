#include<stdio.h>
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int f[n], t[n], maxjoy[n], i;
    for(i = 0; i < n; i++){
        scanf("%d%d", &f[i], &t[i]);
        if(t[i] > k)
            maxjoy[i] = f[i] - ( t[i] - k);
        else
            maxjoy[i] = f[i];
    }
    int max = maxjoy[0];
    for(i = 0; i < n; i++){
        if(maxjoy[i] > max)
            max = maxjoy[i];
    }
    printf("%d", max);
    return 0;
}
