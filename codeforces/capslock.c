#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    gets(s);
    int i, l = 0;
    for(i = 1; i < strlen(s); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            l++;
    }
    if(l == strlen(s) - 1){
        for(i = 0; i < strlen(s); i++){
            if(s[i] >= 'a')
                    s[i] -= 32;
            else if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] += 32;
        }
    }
    printf("%s\n", s);
    return 0;
}
