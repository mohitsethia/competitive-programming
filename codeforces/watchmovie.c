#include<stdio.h>
int main(){
    int n, x, l, r, min = 0;
    scanf("%d%d", &n, &x);
    int a = 1;
    while(n--){
        scanf("%d%d", &l, &r);
        while(a <= l){
            a += x;
        }
        a -= x;
        min += r - a + 1;
        a = r + 1;
    }
    printf("%d", min);
    return 0;
}
