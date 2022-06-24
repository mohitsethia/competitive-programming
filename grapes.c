#include<stdio.h>
int main(){
    int x, y, z, a, b, c, i = 0;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &a, &b, &c);
    if(a + b + c >= x + y + z){
	    if(a - x < 0)
	        printf("NO\n");
	    else{
	        if(a + b - x -y < 0)
		        printf("NO\n");
	        else{
		        i = a + b - x - y;
		        if(c + i - z < 0)
		            printf("NO\n");
		        else
		            printf("YES\n");
            }
        }
    }   
    else
        printf("NO\n");
}

