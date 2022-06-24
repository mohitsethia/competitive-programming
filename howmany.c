#include<stdio.h>
int main(){
	long int i;
	scanf("%ld", &i);
	if(i >= 0 && i < 10)
		printf("1");
		else if(i >= 10 && i < 100)
			printf("2");
			else if(i >= 100 && i < 1000)
				printf("3");
				else
					printf("More than 3 digits");
}