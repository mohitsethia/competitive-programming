#include<stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        long long int n, query;
        scanf("%lld%lld", &n, &query);
        int a[n], i, s = 0, c = 0;
        for(i = 0; i <= n; i++)
            a[i] = i;
        for(i = 0; i < query; i++){
            long long int t, p, q, l, r, y, x, j;
            scanf("%lld", &t);
            if(t == 1){
                scanf("%lld", &y);
                x = y + s;
                a[x] = 0;
            }
            if(t == 2){
                scanf("%lld%lld", &p, &q);
                l = p + s;
                r = q + s;
                long long int max = a[l];
                for(j = l; j <= r; j++){
                    if(a[j] > max)
                        max = a[j];
                }
                printf("%lld\n", max);
                c += max;
                s = c % n;
            }
        }
    }
    return 0;
}
