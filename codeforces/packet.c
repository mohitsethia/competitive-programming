#include<stdio.h>
int main(){
	int n, i, m;
	scanf("%d", &n);
	for(i = 1, m = 0; i <= n; i = i * 2){
		m++;
}
	printf("%d", m);
}