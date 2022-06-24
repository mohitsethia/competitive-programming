#include<stdio.h>
int main(){
    int n, count = 0, s = 5;
    scanf("%d", &n);
    while(n != 0){
        if(n >= s){
            n -= s;
            count++;
}
        else
            s--;
}
        printf("%d", count);
    return 0;
}
