// C++ implementation to find the
// minimum number of sequence
// required from array such that
// their sum is equal to given S

#include <bits/stdc++.h>
using namespace std;

// Function to find the count of
// minimum length of the sequence
int Count(int S[], int m, int n)
{
	vector<vector<int> > table(
		m + 1,
		vector<int>(
			n + 1, 0));

	// Loop to intialize the array
	// as infinite in the row 0
	for (int i = 1; i <= n; i++) {
		table[0][i] = INT_MAX - 1;
	}

	// Loop to find the solution
	// by pre-computation for the
	// sequence
	for (int i = 1; i <= m; i++) {

		for (int j = 1; j <= n; j++) {
			if (S[i - 1] > j) {
				table[i][j]
					= table[i - 1][j];
			}
			else {

				// Minimum possible
				// for the previous
				// minimum value
				// of the sequence
				table[i][j]
					= min(
						table[i - 1][j],
						table[i][j - S[i - 1]] + 1);
			}
		}
	}
	return table[m][n];
}

// Driver Code
int main()
{
    int x, y;
    cin >> x >> y;
    vector<int> arr;
    atoi
	cout << Count(arr, m, 11);
	return 0;
}

