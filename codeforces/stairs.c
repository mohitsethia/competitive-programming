#include<stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int count = (n + 1)/2;
    int min = (n + 1) / 2;
    int a = 0;
    if(count % m == 0)
        printf("%d", count);
    else{
        while(count >= 0){
            if(min % m == 0){
                printf("%d", min);
                break;
            }
            else{
                if(n < m){
                    printf("-1");
                    break;    
                }
                else{
                    min++;
                    count--;
                    a++;
                }
            }
        }
        if(a > (n+1)/2)
            printf("-1");
    }
    return 0;
}
