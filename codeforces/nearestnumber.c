#include<stdio.h>
int sum(int n){
    int r, a = 0;
    while(n != 0){
        r = n % 10;
        a += r;
        n /= 10;
    }
    return a;
}
int main(){
    int a, i;
    scanf("%d", &a);
    for(i = a; i >= a; i++){
        if(sum(i) % 4 == 0){
            printf("%d", i);
            break;
        }
    }
    return 0;
}
