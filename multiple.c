#include<stdio.h>
int main(){
    int x, y, sum = 0;
    x = 29;
    for(int i = 1; i <= 100; i++){
        y = 29 * i;
        if(y % 100 == 29){
            while(y != 0){
                int a = y % 10;
                sum += a;
                y /= 10;
            }
        if(sum == 29)
            printf("%d", i);
        return 0;
        }
    }
    return 0;
}
