#include<stdio.h>
#include<string.h>

int main(){
    int i, j = 0, count = 0;
    char a[50], b[50];
    scanf("%s", a);
    scanf("%s", b);
    for(i = 0; i < strlen(b); i++){
        if(b[i] == a[j]){
            j++;
        }
    }
    printf("%d\n", j+1);
    return 0;
}
