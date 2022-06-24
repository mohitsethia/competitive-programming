#include<stdio.h>
int rem(int a, int b){
    if(b != 0){
        return rem(b, a % b);
    }
    else
        return a;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, ans;
        scanf("%d%d", &a, &b);
        ans = rem(a, b);
        printf("%d\n", ans);
    }
}
