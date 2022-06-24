#include<iostream>
#include<cstring>
using namespace std;
void replace(char a[], int t){
	if(a[t] == '\0'){
		return;
	}
	if(a[t] == 'p' && a[t+1] == 'i'){
		int j, q;
		q = strlen(a);
		for(j = q+2; j > t; j--){
			a[j] = a[j-2];
		}
		a[t++] = '3';
		a[t++] = '.';
		a[t++] = '1';
		a[t] = '4';
	}
	replace(a, t+1);
}
int main(){
	int n;
	cin >> n;
	int i;
	for(i = 0; i < n; i++){
		char a[1000];
		cin >> a;
		replace(a, 0);
		cout << a << endl;
	}
	return 0;
}
