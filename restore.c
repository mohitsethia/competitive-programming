#include<stdio.h>

int main(){
    int x[4], i, j, a, b, c, count = 0;
    for(i = 0; i < 4; i++)
        scanf("%d", &x[i]);
    for(i = 0; i < 3; i++){
        for(j = i + 1; j < 4; j++){
            if(x[i] > x[j]){
                count = x[i];
                x[i] = x[j];
                x[j] = count;
}
}
}
        c = x[3] - x[0];
        b = x[2] - c;
        a = x[0] - b;
        printf("%d %d %d", c, b, a);
    return 0;
}
