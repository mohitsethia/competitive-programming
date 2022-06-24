#include<stdio.h>
int main(){
    int n, s, ans = 0;
    scanf("%d%d", &n, &s);
    while(s!=0){
        if(s>=n){
            s -= n;
            ans++;
}
        else
            n--;
}
    printf("%d", ans);
    return 0;
}
