#include<stdio.h>
int main(){
    int a, b, diff1, diff2;
    scanf("%d%d", &a, &b);
    int i, a1 = 0, b1 = 0, draw = 0;
    for(i = 1; i <= 6; i++){
        if(a > i)
            diff1 = a - i;
        else
            diff1 = i - a;
        if(b > i)
            diff2 = b - i;
        else
            diff2 = i - b;
        if(diff1 < diff2)
            a1++;
        else if(diff2 < diff1)
            b1++;
        else
            draw++;
    }
    printf("%d %d %d", a1, draw, b1);
    return 0;
}
