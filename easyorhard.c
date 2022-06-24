#include<stdio.h>
int a,n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
	}
	if(a == 1){
		printf("Hard");
	}
	else
		printf("Easy");
	return 0;
}