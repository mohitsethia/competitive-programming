#include<stdio.h>
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n, k, sum = 0;
        scanf("%d%d", &n, &k);
        int a, i;
        for(i = 0; i < n; i++){
            scanf("%d", &a);
            sum += a / k;
}
        printf("%d\n", sum);
}
    return 0;
}
