#include<stdio.h>
int main(){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if(x == y){
        if(z == 0)
            printf("0");
        else
            printf("?");
    }
    else if(x > y){
        if(y + z > x)
            printf("?");
        else
            printf("+");
    }
    else if(y > x){
        if(x + z > y)
            printf("?");
        else
            printf("-");
    }
    return 0;
}
