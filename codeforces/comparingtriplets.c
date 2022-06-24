#include<stdio.h>
int main(){
	int m = 0, n = 0, a[3], b[3];
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	scanf("%d%d%d", &b[0], &b[1], &b[2]);
	for(int i = 0; i < 3; i++){
		if(a[i] > b[i])
			m++;
		else if(a[i] < b[i])
			n++;
	}
	printf("%d\t%d", m, n);
}
/* 
*first we scan the arrays of alice and bob
*then we compare each array 
*if a[i] > b[i], then alice recieves a point
*if a[i] < b[i], then bob receives a point
*if a[i] = b[i], then neither alice or bob recieves a point
*so what we need to do is count how much does alice earns and bob earns
*then print alice's and bob's points.
*/