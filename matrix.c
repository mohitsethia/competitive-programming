#include<stdio.h>
int main(){
    int r, c, x, y;
    int a[5][5];
    for(r = 0; r < 5; r++){
        for(c = 0; c < 5; c++)
            scanf("%d", &a[r][c]);
}
    for(r = 0; r < 5; r++){
        for(c = 0; c < 5; c++){
            if(a[r][c] == 1){
                x = r + 1;
                y = c + 1;
}
}
}
    if(x < 3)
        x = 3 - x;
    else
        x = x - 3;
    if(y < 3)
        y = 3 - y;
    else
        y = y - 3;
    int z = x + y;
    printf("%d", x + y);
    return 0;
}
