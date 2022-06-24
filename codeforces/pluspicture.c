#include<stdio.h>
#include<math.h>
int main(){
    int h, w, i, j, c = 0, d = 0, count = 0, n = 0;
    scanf("%d%d", &h, &w);
    getchar();
    char a[h+1][w+1];
    for(i = 0; i < h; i++)
        gets(a[i]);
    if(h <= 2 && w <= 2)
        printf("NO");
    else{
        for(i = 0; i < h; i++){
            for(j = 0; j < w; j++){
                if(a[i][j] == '*' && a[i+1][j] == '*' && a[i-1][j] == '*' && a[i][j+1] == '*' && a[i][j-1] == '*'){
                    c = i;
                    d = j;
                    n++;
                }
            }
        }
        for(i = c; i >= 0; i--){
            if(a[i][d] == '*')
                a[i][d] = '.';
            else
                break;
        }
        for(i = c+1; i < h; i++){
            if(a[i][d] == '*')
                a[i][d] = '.';
            else
                break;
        }
        for(j = d-1; j >= 0; j--){
            if(a[c][j] == '*')
                a[c][j] = '.';
            else
                break;
        }
        for(j = d+1; j < w; j++){
            if(a[c][j] == '*')
                a[c][j] = '.';
            else
                break;
        }
    
    for(i = 0; i < h; i++)
        for(j = 0; j < w; j++)
            if(a[i][j] == '*')
                count++;
    if(count == 0 && n == 1)
        printf("YES");
    else
        printf("NO");
    }
    return 0;
}
