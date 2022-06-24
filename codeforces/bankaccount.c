#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    if(n < 0){
        int x ,y;
        x = n / 10;
        y = (n % 10)+ ((n / 100) * 10); 
        if(x > y)
            printf("%d", x);
        else
            printf("%d", y);
    }
    else
        printf("%d", n);
    return 0;
}
