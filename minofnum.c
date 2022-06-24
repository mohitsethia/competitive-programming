#include<stdio.h>
int main(){
	int a[n], i, n, smallest, T;
	scanf("%d", &T);
	while(T--){
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	smallest = a[0];
	for(i = 0; i < n; i++){
		if(a[i] < smallest){
			smallest = a[i];
		}
	}
	printf("%d", smallest);
}
	return (0);
}