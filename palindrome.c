/*

#include<stdio.h>
int reverse(long long int n){
    long long int k = n, r = 0;
    while(k != 0){
        r *= 10;
        r += (k % 10);
        k /= 10;
    }
    return r;
}
int main(){
    long long int i, n, T, k;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld", &n);
        for(i = n + 1;; i++){
            if(i == reverse(i)){
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}

*/

#include<stdio.h>
#include<string.h>
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char *n = (char*)malloc(sizeof(char)*1000000);
        scanf("%s", n);
        long long int i, count = 0;
        if(strlen(n) % 2 != 0){
            for(i = 0; i < strlen(n)/2; i++){
                if(n[i] != n[strlen(n) - i - 1])
                    count = 1;
            }
        }
        else{
            for(i = 0; i < strlen(n)/2; i++){
                if(n[strlen(n)/2 - i] != n[(strlen(n)+1)/2 +i])
                    count = 1;
            }
        }
        if(count == 0)
            printf(
    }
    return 0;
}
