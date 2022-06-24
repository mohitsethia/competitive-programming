#include<stdio.h>
int main(){
    long long int x, y, z, i, j, k, l, m, n;
    scanf("%lld%lld%lld", &x, &y, &z);
    i = (x + y) / z;
    l = (x/z) + (y/z);
    if(i == l){
        printf("%lld 0", i);
        return 0;
    }
    j = (x % z);
    m = z - j;
    k = (y % z);
    n = z - k;
    if(m < n)
        printf("%lld %lld", i, m);
    else
        printf("%lld %lld", i, n);
    return 0;
}
