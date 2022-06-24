#include<stdio.h>
int main(){
    int n, k, l, c, d, p, nl, np;
    scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
    int tl, toast, lime, salt, min;
    tl = (k * l);
    toast = tl / nl;
    lime = c * d;
    salt = p / np;
    if(toast < lime){
        if(toast < salt)
            min = toast;
        else
            min = salt;
    }
    else{
        if(lime < salt)
            min = lime;
        else
            min = salt;
    }
    printf("%d\n", min/n);
    return 0;
}
