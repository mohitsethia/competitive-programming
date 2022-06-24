#include<stdio.h>
long long int min(long long int x, long long int y){
    if(x < y)
        return x;
    else
        return y;
}
int main(){
    long long int T, n, s, t;
    scanf("%lld", &T);
    while(T--){
    long long int ans = 0;
        scanf("%lld%lld%lld", &n, &s, &t);
        ans = n - min(s, t);
        printf("%lld\n", ans+1);
    }
    return 0;
}
