#include<stdio.h>
int main(){
    long long int t;
    scanf("%lld", &t);
    while(t--){
        long long int n;
        scanf("%lld", &n);
        long long int a[n], i, j = 0, k, l;
        for(i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        long long int max = -1, min = -1;
        for(k = 0; k < n; k++){
            if(a[k] > max){
                max = a[k];
                j = k;
            }
        }
        for(l = 0; l < n; l++){
            if(a[l] > min && l != j)
                min = a[l];
        }
        long long int ans = min-1;
        if((n - 2) < ans)
            ans = (n - 2);
        printf("%lld\n", ans);
    }
    return 0;
}

