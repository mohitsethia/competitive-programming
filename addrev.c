#include<stdio.h>
#include<math.h>
long long int rev(long long int a){
    long long int ans = 0, i = log10(a);
    while(a != 0){
        ans += (a % 10) * pow(10, i);
        i--;
        a /= 10;
    }
    return ans;
}
int main(){
    long long int t;
    scanf("%lld", &t);
    while(t--){
        long long int a, b, c, d;
        scanf("%lld%lld", &a, &b);
        long long int ans = rev(a) + rev(b);
        printf("%lld\n", rev(ans));
    }
    return 0;
}
