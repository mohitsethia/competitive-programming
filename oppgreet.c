#include<stdio.h>
int main(){
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        if(n > 10){
            int m = n - 10;
            int k = 10;
            printf("%d %d\n", m, k);
}
        else{
            int m = 0;
            printf("%d %d\n", m, n);
}
}
    return 0;
}
