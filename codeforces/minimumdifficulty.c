#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, max = 0, min = 1000000000;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(i >= 1){
            if(a[i] - a[i-1] > max)
                max = a[i] - a[i-1];
        }
        if(i >= 2){
            if(a[i] - a[i-2] < min)
                min = a[i] - a[i-2];
        }
    }
    if(min > max)
        printf("%d\n", min);
    else
        printf("%d\n", max);
    return 0;
}
