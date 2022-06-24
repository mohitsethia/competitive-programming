#include<stdio.h>
#include<string.h>
int main(){
    int i, j, n;
    char a[100000], b[100008];
    scanf("%d", &n);
    for(i = 0, j = n*n-1; i < n*n; i++, j--){
        scanf(" %c", &a[i]);
        b[j] = a[i];
    }
    if(strcmp(b, a) == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
