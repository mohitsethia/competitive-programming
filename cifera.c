#include<stdio.h>
long long int fact(long long int n, long long int m){
    long long int i, prod = 1, count = 0;
    for(i = 1;; i++){
        if(prod == m){
            count--;
            return count;
        }
        if(prod > m){
            count = -1;
            return count;
        }
        prod *= n;
        count++;
    }
}
int main(){
    long long int n, m;
    scanf("%lld%lld", &n, &m);
    long long int p = fact(n, m);
    if(p >= 0){
        printf("YES\n");
        printf("%lld", p);
    }
    else
        printf("NO\n");
    return 0;
}
