#include<stdio.h>
int main(){
	float b, d;
	int a, c;
	scanf("%d%f", &a, &b);
	c = a % 5;
	d = (b - a) - 0.50;
	if(((a + 0.50) < b) && (c == 0))
	printf("%.2f", d);
	else
	printf("%.2f", b);
	return 0;
}