#include<stdio.h>
int main(){
    int n, i,count = 0;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
        for(i = 0; i < n; i++){
            if(s[i] % 2 == 0)
                count += i+1;
        }
    printf("%d", count);
    return 0;
}
