#include<stdio.h>
int main(){
    int a[3], d, i, j, k = 0, l = 0;
    scanf("%d%d%d%d", &a[0], &a[1], &a[2], &d);
    for(i = 0; i < 2; i++){
        for(j = i+1; j < 3; j++){
            if(a[i] > a[j]){
                int swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    if(a[1] - a[0] < d)
        k = a[0] - a[1] + d;
    if(a[2] - a[1] < d)
        l = a[1] - a[2] + d;
    printf("%d", k+l);
    return 0;
}
