#include<stdio.h>
int main(){
    int n, a, b, c, i, j, flag = 0, temp = 0;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    for(i = 0; i <= n; i++){
        for(j = 0; j <= n; j++){
            if((i*a+j*b) <= n){
                if((n - (i*a + j*b)) % c == 0){
                    flag = i + j + (n-(i*a + j*b))/c;
                    if(flag > temp && flag != 0){
                        temp = flag;
                    }
                }
            }
        }
    }
    printf("%d\n", temp);
    return 0;
}
