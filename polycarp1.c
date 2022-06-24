#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n, i, j, p;
    char a[1000000], b[1000000];
    scanf("%d", &n);
    while(n--){
        getchar();
        gets(a);
        getchar();
        gets(b);
        i = 0; p = 0;
        if(strlen(a) > strlen(b))
            printf("NO\n");
        else{
            for(j = 0; j < strlen(b); j++){
                if(b[j] == a[i])
                    i++;
                else if(i == 0 || b[j] != a[i-1]){
                    p = 1;
                    break;   
                }
            }
            if(p == 1 || i != strlen(a))
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
