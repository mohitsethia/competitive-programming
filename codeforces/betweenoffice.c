#include<stdio.h>
int main(){
    int n, i;
    scanf("%d", &n);
    char a[n];
        scanf("%s", a);
    if(a[0] == 'S' && a[n-1] == 'F'){
        printf("YES\n");
    }
    else
        printf("NO\n");
    return 0;
}
