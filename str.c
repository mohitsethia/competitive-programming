#include<stdio.h>
int main(){
    char c[100];
    int i = 0, words = 0;
    char prevchar;
    char s[100];
    gets(c);
    prevchar = '\0';
    while(1){
        if(c[i] == ' ' || c[i] == '\t' || c[i] == '\n' || c[i] == '\0'){
            if(prevchar != '\n' && prevchar != ' ' && prevchar != '\t' && prevchar != '\0'){
                words++;
            }
        }
        prevchar = c[i];
        if(c[i] == '\0')
            break;
        else
            i++;
    }
    printf("%d", words);
    return 0;
}
