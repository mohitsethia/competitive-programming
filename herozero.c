#include<stdio.h>
int main(){
    int T, i;
    scanf("%d", &T);
    for(i = 0; i < T; i++){
        long long int count = 0, n, k, p, d;
        scanf("%lld%lld", &n, &k);
        while(n != 0){
            if(n % k == 0){
                n /= k;
                count++;
            }
            else{
                d = n/k;
                p = d * k;
                count += (n-p);
                n = p;
            }
        }
        printf("%lld\n", count);
    }
    return 0;
}
