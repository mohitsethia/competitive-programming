#include<stdio.h>
#include<string.h>
int main(){
    int T, n, i, j, k, l;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        char s[n][10];
        k = 0; l = 0;
        for(i = 0; i < n; i++)
            scanf("%s", s[i]);
        for(i = 0; i < n; i++){
            for(j = 0; j < strlen(s[i]); j++){
                if(s[i][j] >= 'a' && s[i][j] <= 'z')
                    k = i;
                if(s[i][j] == '#'){
                    l++;
                    break;
                }
            }
        }
        if(l == n)
            for(i = 0; i < n; i++)
                printf("%s ", s[i]);
        else{
            for(i = n-1; i >= k; i--)
                printf("%s ", s[i]);
            for(i = 0; i < k; i++)
                printf("%s ", s[i]);
        }
        printf("\n");
    }
    return 0;
}
