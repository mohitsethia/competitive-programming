#include<stdio.h>
#include<string.h>

int main(){
    int n, i, j, count = 0, f = 0;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);

    for(i = 1; i < strlen(s); ++i){
        if(s[i] < s[i-1]){
            printf("YES\n");
            printf("%d %d\n", i, i + 1);
            return 0;
        }
    }
        printf("NO\n");
    return 0;
}
