#include<stdio.h>
#include<string.h>

int main(){
    char s[50];
    int i, count = 0;
    gets(s);
    for(i = 0; i < strlen(s); i++){
        if(s[i] == 'a')
            count++;
    }
    if(count > (strlen(s)/2)){
        printf("%d", strlen(s));
    }
    else
        printf("%d", (count*2) - 1);
    return 0;
}
