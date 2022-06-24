#include<stdio.h>
#include<ctype.h>

#define SIZE 400
char s[SIZE];
int top = -1;

void push(char elem){
    s[++top] = elem;
}
char pop(){
    return(s[top--]);
}
int precedence(char elem){
    switch(elem){
        case '#':
                return 0;
        case '(':
                return 1;
        case '+':
        case '-':
                return 2;
        case '*':
        case '/':
                return 3;
        case '^':
                return 4;
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char infx[400], pofx[400], ch, elem;
        int i = 0, k = 0;
        scanf("%s", infx);
        push('#');
        while((ch = infx[i++]) != '\0'){
            if(ch == '(')
                push(ch);
            else{
                if(isalnum(ch))
                    pofx[k++] = ch;
                else{
                    if(ch == ')'){
                        while(s[top] != '('){
                            pofx[k++] = pop();
                        }
                        elem = pop();
                    }
                    else{
                        while(precedence(s[top]) >= precedence(ch)){
                            pofx[k++] = pop();
                        }
                        push(ch);
                    }        
                }
            }
        }
        while(s[top] != '#'){
            pofx[k++] = pop();
        }
        pofx[k] = '\0';
        printf("%s\n", pofx);
    }
}
