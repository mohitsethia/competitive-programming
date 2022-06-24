#include<stdio.h>
#include<string.h>
int main(){
    int T;
    char s[100];
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        char candy;
        int count = 0, letter[26];
        for(int i = 0; i < 26; i++)
            letter[i] = 0;
        for(int i = 0; i < strlen(s); i++)
            letter[(int)s[i] - 97]++;
        for(int i = 0; i < 26; i++){
            if(letter[i] > count){
                count = letter[i];
                candy = (char)i + 97;
            }
        }
        printf("%d %c\n", count, candy);
    }
    return 0;
}
