#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        long long int n;
        scanf("%lld", &n);
        long long int a[n], b[n], s1 = 0, s2 = 0, i, j, s = 0;
        for(i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            s1 += a[i];
        }
        for(j = 0; j < n; j++){
            scanf("%lld", &b[j]);
            s2 += b[j];   
        }
        s = (s1 + s2 - 1)/2;
        printf("%lld\n", s);
    }
    return 0;
}
