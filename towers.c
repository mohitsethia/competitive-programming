#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, j, max = 0, c = 1, s = 1;
    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if(n == 1){
        printf("1 1");
        return 0;
    }
    for(i = 1; i < n; i++){
        for( j = i + 1; j <= n; j++){
            if(a[i] == a[j])
                c++;
        }
        if(max < c)
            max = c;
        c = 1;
    }
    for(i = 1; i < n ; i++){
        for( j = i + 1; j <= n; j++){
            if(a[i] > a[j]){
                int swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    for(i = 1; i < n; i++){
        if(a[i] != a[i+1])
            s++;
    }
    printf("%d %d", max, s);
    return 0;
}
