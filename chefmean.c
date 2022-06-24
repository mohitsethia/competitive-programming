#include<stdio.h>
int main(){
    long long int t, n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        long long int count = 0, i;
        long double a[n], c = 0;
        for(i = 0; i < n; i++){
            scanf("%Lf", &a[i]);
            c += a[i];
        }
        for(i = 0; i < n; i++){
            if(((c/n) * 1.0) == ((c-a[i])/(n-1.0))){
                printf("%lld\n", i+1);
                break;
            }
            else
                count++;
        }
        if(count == n){
            printf("Impossible\n");
        }
    }
    return 0;
}
