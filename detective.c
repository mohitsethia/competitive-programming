#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], k, i, count = 0;
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    k = a[1];
    for(i = 1; i <= n; i++){
        if(a[i] > k){
            k = a[i];
        }
        if(k == i){
            k++;
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
