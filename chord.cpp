#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// int m = 8;
	// int n = 6;
	// int arr[] = {45, 32, 132, 234, 99, 199};
	int m = 8;
	int n = 6;
	int arr[] = {45, 95, 145, 195, 245, 254, 100};
	sort(arr, arr+n);
	n++;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	for(int i = 0; i < n; i++) {
		cout << "finger table for node " << arr[i] << "\n";
		for(int p = 0; p < m; p++) {
			int z = ((int)(arr[i]+pow(2, p)) % (int)pow(2, m));
			bool found = false;
			for(int j = 0; j < n; j++) {
				if(arr[j] >= z) {
					cout << arr[j] << "\n";
					found = true;
					break;
				}
			}
			if(!found) {
				cout << arr[0] << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}