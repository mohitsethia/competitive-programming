#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
    char n[31];
    long long int i, j = 0, k=0, l;
    scanf("%s", n);
    long long int m = strlen(n);
    while(m != 0){
        i = n[m-1];
        if(i == 1)
            k += pow(2, j);
        j++;
        m--;
    }
    printf("%lld", k);
/*
    for(l = 0; l <= 100; l++){
        long long int p = pow(2, l);
        if(p < k){
            printf("%lld", l);
            break;
        }
        else if(p == k){
            printf("%lld", l-1);
            break;
        }
        else
            continue;
    }
*/
    return 0;
}
