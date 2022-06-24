#include<stdio.h>
int main(){
    int n, k = 0;
    scanf("%d", &n);
    int a[n], i, j, b[n], count = 0;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++){
        for(j = i+1; j < n; j++){
            if(a[i] > a[j]){
                int swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    for(i = 0; i < n; i++){
        if(a[i] != a[i+1]){
            b[k] = a[i];
            count++;
            k++;
        }
    }
    if(count > 3)
        printf("-1");
    else{
        if(count == 3){
            if(b[2] - b[1] == b[1] - b[0])
                printf("%d", b[1] - b[0]);
            else
                printf("-1");
        }
        else if(count == 2){
            if((b[1]- b[0]) % 2 == 0)
                printf("%d", (b[1] - b[0])/2);
            else
                printf("%d", b[1] - b[0]);
        }
        else
            printf("0");
    }
    return 0;
}
