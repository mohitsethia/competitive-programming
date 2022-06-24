#include<stdio.h>
int main(){
	int a = 0;
	while(scanf("%d\n", &a) > 0 && a != 42)
		printf("%d\n", a);
	return 0;
}
