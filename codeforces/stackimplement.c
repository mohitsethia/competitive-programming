#include<stdio.h>
#include<ctype.h>

#define SIZE 100
char a[SIZE];
char b[SIZE];
void push(int *top, int element){
    top++;
    a[top] = element;
}
char pop(int *top){
    return a[top--];
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int q, ch, x, top = -1, k = 0, i;
        scanf("%d", &q);
        while(q--){
            scanf("%d", &ch);
            switch(ch){
                case 1:
                    scanf("%d", &x);
                    push(&top, x);
                    break;
                case 2:
                    b[k] = pop(&top);
                    k++;
                    break;
            }
            for(i = 0; i < k; i++){
                printf("%d ", b[i]);
            }
        }
        printf("\n");
    }
}
