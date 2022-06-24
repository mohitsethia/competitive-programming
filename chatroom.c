#include<stdio.h>
#include<string.h>
int main(){
    char s[100];
    int i, sum = 0, a = 0;
    gets(s);
    int n = strlen(s);
    for(i = 0; i < n; i++){
        if(s[i] == 'h'){
            a = i;
            sum++;
            break;
}
}
    for(i = a + 1; i < n; i++){
        if(s[i] == 'e'){
            a = i;
            sum++;
            break;
}
}
    for(i = a + 1; i < n; i++){
        if(s[i] == 'l'){
            a = i;
            sum++;
            break;
}
}
    for(i = a + 1; i < n; i++){
        if(s[i] == 'l'){
            a = i;
            sum++;
            break;
}
}
    for(i = a + 1; i < n; i++){
        if(s[i] == 'o'){
            sum++;
            break;
}
}
    if(sum == 5)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
