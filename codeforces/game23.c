#include<stdio.h>
int main(){
    int n, m, x, count = -1;
    scanf("%d%d", &n, &m);
    x = m/n;
    if(m % n == 0){
        count = 0;
        while(x % 2 == 0){
            count++;
            x /= 2;
        }
        while(x % 3 == 0){
            count++;
            x /= 3;
        }
        if(x != 1)
            count = -1;
    }
    printf("%d", count);
    return 0;
}
