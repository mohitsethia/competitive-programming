#include<stdio.h>
int sum(int a[], int n){
    int i, s = 0;
    for(i = 0; i < n; i++){
        s += a[i];
    }
    return s;
}
int main(){
    int n;
    scanf("%d", &n);
    int i, j, a[n], b[n], count = 0, p, q;
    for(i = 0; i < n; i++){
        scanf("%d%d", &a[i], &b[i]);
    }
    p = sum(a, n);
    q = sum(b, n);
    if(p%2 == 0 && q%2 == 0){
        printf("0\n");
    }
    else{
        if(n >= 2){
            for(i = 0; i < n; i++){
                int swap = a[i];
                a[i] = b[i];
                b[i] = swap;
                count++;
                if(sum(a, n)%2 == 0 && sum(b, n)%2 == 0){
                    if(count > 0){
                        printf("1");
                    }
                    break;
                }
                else if(count == n-1){
                    printf("-1");
                }
                else
                    continue;
            }
        }
        else
            printf("-1");
    }
    return 0;
}
