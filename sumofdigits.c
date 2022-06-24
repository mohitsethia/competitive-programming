#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int T = 0;
	long long int sum = 0;
    int *s = (int*)malloc(sizeof(int)*(int)pow(10, 50));
    int *i = (int*)malloc(sizeof(int)*(int)pow(10, 50));
	scanf("%d", &T);
	while(T--){
	sum = 0;
	scanf("%d", s);
	for(i = s; i > 0; i /= 10){
	sum += (i % 10);
	}
	printf("%lld\n", sum);
	}
}
