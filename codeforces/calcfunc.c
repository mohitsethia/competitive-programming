#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    long long n, sum = 0, ans = 0, i;
    scanf("%I64d", &n);
    for(i = 1; i <= n; i++){
        int b = -1;
        ans = pow(b, i);
        sum += (ans * i);
    }
    printf("%I64d", sum);
    return 0;
}
