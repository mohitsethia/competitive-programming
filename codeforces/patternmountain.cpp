#include<iostream>
using namespace std;
int main() {
	int n, i, j, space = 0;
	cin >> n;
	int x = n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= i; j++){
			cout << j << " ";
		}
		for(space = 1; space <= 2 * (n-i) - 1; space++){
			cout << " ";
		}
		for(j = i; j > 0; j--){
			if(j != n){
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
