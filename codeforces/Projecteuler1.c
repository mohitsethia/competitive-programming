#include<stdio.h>
int main(){
	int i, sum = 0, sum2 = 0, sum1 = 0;
	for(i = 3; i < 1000; i++){
		if(i%3 == 0){
			sum += i;
		}
		if(i%5 == 0){
			sum1 += i;
		}
		if(i % 15 == 0){
			sum2 += i;
		}
	}
	printf("%d\n", sum + sum1 - sum2);
}