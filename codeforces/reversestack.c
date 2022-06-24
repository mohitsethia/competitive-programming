#include<stdio.h>
#include<string.h>

#define SIZE 100000
char arr[SIZE];
int top = -1;

void push(char x){
    arr[++top] = x;
}

char pop(){
    if(top == -1)
        return -1;
    return arr[top--];
}
int main(){
    char str[SIZE];
    scanf("%s", str);
    int i = 0, j = 0, l = strlen(str);
    for(i = 0; i < l; i++){
        push(str[i]);
    }
    for(i = 0; i < l; i++){
        str[i] = pop();
    }
    printf("Reversed string is %s\n", str);
    return 0;
}
