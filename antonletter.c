#include<stdio.h>
#include<string.h>

int main(){
    char s[26] = "abcdefghijklmnopqrstuvwxyz";
    int count = 0, i, j;
    char a[1000];
    gets(a);
    for(j = 0; j < 26; j++){
        for(i = 1; i < strlen(a); i += 3){
            if(s[j] == a[i]){
                count++;
                break;
            }
        }
    }
        printf("%d\n", count);
    return 0;
}
