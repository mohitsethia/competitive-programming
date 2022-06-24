#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int right(int x1, int y1, int x2, int y2, int x3, int y3){
    int a = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
    int b = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    int c = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    if(a == 0 || b == 0 || c == 0){
        return 0;
    }
    if((a + b == c) || (b + c == a) || (a + c == b)){
        return 1;
    }
    return 0;
}
int main(){
    int x1, x2, x3, y1, y2, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    if(right(x1, y1, x2, y2, x3, y3)){
        printf("RIGHT\n");
    }
    else{
        int almost = 0;
        for(int i = 0; i < 4; i++){
            almost |= right(x1+dx[i], y1+dy[i], x2, y2, x3, y3);
            almost |= right(x1, y1, x2+dx[i], y2+dy[i], x3, y3);
            almost |= right(x1, y1, x2, y2, x3+dx[i], y3+dy[i]);
        }
        if(almost){
            printf("ALMOST\n");
        }
        else{
            printf("NEITHER\n");
        }
    }
    return 0;
}
