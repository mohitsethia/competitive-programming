#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d", &n);
    char s[100];
    while(n--){
        scanf("%s", s);
        int count = 0, i, j;
        for(i = 0; i < strlen(s); i++){
            for(j = i + 1; j < strlen(s); j++){
                if(s[i] > s[j]){
                    char c = s[i];
                    s[i] = s[j];
                    s[j] = c;
                }
            }
        }
        for(i = 0; i < strlen(s); i++){
            if(s[i] == s[i+1])
                count--;
            else if(s[i+1] - s[i] > 1)
                count--;
            else
                count++;
        }
    if(count == strlen(s))
        printf("Yes\n");
    else
        printf("No\n");
    }
    return 0;
}
