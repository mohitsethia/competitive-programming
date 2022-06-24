/*
#include<stdio.h>
int* sortandsub(int *a, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i+1; j < n; j++){
            if(a[i] > a[j]){
                a[i] = a[i] - a[j];
            }
            else if(a[j] > a[i]){
                a[j] -= a[i];
            }
        }
    }
    return a;
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n], i, j;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(a[i] != a[j]){
                sortandsub(a, n);
            }
        }
    }
    printf("%d", n * a[0]);
    return 0;
}
*/
#include <stdio.h>
 
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
 
int main() {
	int n, n_, g = 0;
 
	scanf("%d", &n);
	n_ = n;
	while (n--) {
		int x;
 
		scanf("%d", &x);
		g = gcd(x, g);
	}
	printf("%d\n", g * n_);
	return 0;
}
