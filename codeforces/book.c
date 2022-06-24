#include<stdio.h>
int main(){
    int i;
    for(i = 5; i < 100; i++){
        if(i % 3 == 2 && i % 4 == 3 && i % 5 == 4){
            printf("%d", i);
        }
    }
    return 0;
}
