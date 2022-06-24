#include<stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int i, j;
    scanf("%d%d", &i, &j);
    swap(&i, &j);
    printf("%d %d", i, j);
}
