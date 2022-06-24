#include<stdio.h>
int main(){
    int r, c, i, j, l = 0, m = 0;
    scanf("%d%d", &r, &c);
    char a[r][c];
    for(i = 0; i < r; i++)
           scanf("%s", a[i]);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(a[i][j] == 'S'){
                l++;
                break;
            }
        }
    }
    for(j = 0; j < c; j++){
        for(i = 0; i < r; i++){
            if(a[i][j] == 'S'){
                m++;
                break;
            }
        }
    }
    printf("%d", (r*c) - (l*m));
    return 0;
}
