#include<stdio.h>
int main(){
	int x, y, z, T;
	scanf("%d", &T);
	while(T--){
	scanf("%d%d%d", &x, &y, &z);
	if((x + y == z) || (x + z == y) || (y + z == x))
	printf("yes\n");
	else
	printf("no\n");
	}
	return 0;
}