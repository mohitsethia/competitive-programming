#include<stdio.h>
int main(){
    int n, m, a, b, x;
    scanf("%d%d%d%d" ,&n, &m, &a, &b);
    if(m*a > b){
        x = n/m;
        if(((n % m) * a) < b)
            printf("%d", (x*b) + ((n % m) * a));
        else
            printf("%d", (x*b) + b);
    }
    else
        printf("%d", n*a);
    return 0;
}
