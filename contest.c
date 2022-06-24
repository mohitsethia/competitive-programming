#include<stdio.h>
int max(int point, int time){
    if(point >= time)
        return point;
    else
        return time;
}
int pointcalc(int a){
    int x;
    x = (3*a)/10;
    return x;
}
int timecalc(int a, int c){
    int y;
    y = a - ((a * c) / 250);
    return y;
}
int main(){
    int z, a, b, c, d, i, j, k, l, x, y;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    i = pointcalc(a);
    j = pointcalc(b);
    k = timecalc(a, c);
    l = timecalc(b, d);
    x = max(i, k);
    y = max(j, l);
    if(x > y)
        printf("Misha");
    else if(x < y)
        printf("Vasya");
    else
        printf("Tie");
    return 0;
}
