#include<stdio.h>
#include<string.h>
int main(){
    int i, j, k = 0, l, b;
    char s[100];
    scanf("%s", s);
    l = strlen(s);
    for(i = 0; i < l; i++){
        if(s[i] != '0'){
            for(j = i + 1; j < l; j++){
                if(s[i] == s[j]){
                    k++;
                    s[j] = '0';
                }
            }
        }
    }
    b = l - k;
    if(b % 2 == 0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");
    return 0;
}   
