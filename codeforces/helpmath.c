#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s", s);
    int count1 = 0, count2 = 0, count3 = 0;
    for(int i = 0; i < strlen(s); i+=2){
        if(s[i] == '1'){
            count1++;
        }
        else if(s[i] == '2'){
            count2++;
        }
        else{
            count3++;
        }
    }
    for(int i = 0; i < strlen(s); i++){
        if(i%2 == 0){
            if(count1 != 0){
                printf("1");
                count1--;
            }
            else if(count2 != 0){
                printf("2");
                count2--;
            }
            else if(count3 != 0){
                printf("3");
                count3--;
            }
        }
        else{
            printf("+");
        }
    }
    return 0;
}
/*
#include<stdio.h>
#include<string.h>

int main(){
    int x;
    char s[100];
    gets(s);
    if(strlen(s) > 1){
        for(int i = 0; i < strlen(s) - 2; i += 2){
            for(int j = 0; j < strlen(s) - i - 2; j += 2){
                if(s[j] > s[j + 2]){
                    x = s[j];
                    s[j] = s[j+2];
                    s[j+2] = x;
}
}
}
        printf("%s", s);
}
    else
        printf("%s", s);
    return 0;
}
*/
