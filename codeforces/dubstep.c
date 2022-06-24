#include<stdio.h>
#include<string.h>
int main(){
    char s[200];
    int i, flag = 1;
    gets(s);
    for(i = 0; i < strlen(s); i++){
        if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
            i += 2;
                printf(" ");
}
        else{
            flag = 0;
            printf("%c", s[i]);
}
}
    return 0;
}
