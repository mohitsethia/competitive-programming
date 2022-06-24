#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int m = 64;
	// ((x^2 + x^3)*1)%m
	// ((x^2 + x^3)*2)%m
	// ((x^2 + x^3)*3)%m
	int a[5] = {1975, 1985, 1995, 2005, 2015};
	int n = 5;
	int set[64] = {0};
	for(int i = 1; i <= 2; i++) {
		for(int j = 0; j < n; j++) {
			long long eq = (a[j]*i)%m;
			if(a[j] == 2015) {
				cout << set[eq] << " ";
				continue;
			}
			set[eq] = 1;
		}
	}
	// for(int i = 0; i < 32; i++) {
	// 	if(set[i]) {
	// 		cout << i << " ";
	// 	}
	// }
	return 0;
}