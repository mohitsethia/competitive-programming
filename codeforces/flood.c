#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int a[n], largest = 0, i, count = 0, same = 0, j;
    for(i = 0; i < n; i++)
	scanf("%d", &a[i]);
	for(i = 0; i < n; i++){
	if(a[i] > largest){
	    largest = a[i];
}
}

for(i = 0; i < n; i++){
if(a[i] < largest)
count++;

}
printf("%d", count);
}
