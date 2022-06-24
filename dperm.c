#include<stdio.h>
int main(){
    int T;
    long long int n, d;
    scanf("%d", &T);
    while(T--){
        scanf("%lld%lld", &n, &d);
        long long int a[n], i, j, swap = 0, c = 0;
        for(i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for(i = 0; i < n-1; i++){
            for(j = i+1; j < n; j++){
                if(a[i] - a[j] == d || a[j] - a[i] == d){
                    if(a[i] > a[j]){
                        int k = a[i];
                        a[i] = a[j];
                        a[j] = k;
                        swap++;
                    }
                }
            }
        }
        for(i = 0; i < n; i++){
            if(a[i] > a[i+1]){
                c = 1;
                break;
            }
        }
        if(c == 1)
            printf("-1\n");
        else
            printf("%lld\n", swap);
    }
    return 0;
}
