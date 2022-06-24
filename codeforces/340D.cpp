#include<iostream>
#include<cstdio>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

// Function to map
// numbers using coordinate
// compression
void coordinateCompression(int arr[], int n)
{

	// Set will store
	// all unique numbers
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(arr[i]);
	}

	// Map will store
	// the new elements
	int index = 0;
	map<int, int> mp;
	set<int>::iterator itr;

	for (itr = s.begin(); itr != s.end(); itr++) {
		// For every new number in the set,
		index++;
		// Increment the index of the
		// current number and store it
		// in a hashmap. Here index
		// for every element is the
		// new value with with the
		// current element is replaced
		mp[*itr] = index;
	}
	for (int i = 0; i < n; i++) {
		// now change the current element
		// to range 1 to N.
		arr[i] = mp[arr[i]];
	}
}

// Function to calculate
// length of maximum
// increasing sequence till
// i'th index
int query(int BIT[], int index, int n)
{

	int ans = 0;
	while (index > 0) {
		ans = max(ans, BIT[index]);
		// Go to parent node
		index -= index & (-index);
	}
	return ans;
}

// Function for updating
// BIT array for maximum
// increasing sequence till
// i'th index
void update(int BIT[], int index, int n)
{

	// If 4 is inserted in BIT,
	// check for maximum length
	// subsequence till element 3.
	// Let this subsequence length be x.
	// If x + 1 is greater than
	// the current element in BIT,
	// update the BIT array
	int x = query(BIT, index - 1, n);
	int value = x + 1;
	while (index <= n) {

		// Store maximum length subsequence length till index
		// Here index is the
		// coordinate compressed element
		BIT[index] = max(BIT[index], value);

		// Go to child node and update that node
		index += index & (-index);
	}
}

// Function to calculate
// maximum Longest Increasing
// Sequence length
int findLISLength(int arr[], int n)
{

	coordinateCompression(arr, n);
	int BIT[n + 1];

	// Initialising BIT array
	for (int i = 0; i <= n; i++) {
		BIT[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		// Add elements
		// from left to right
		// in BIT
		update(BIT, arr[i], n);
	}

	int ans = query(BIT, n, n);
	return ans;
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

	int ans = findLISLength(arr, n);

	cout << ans << endl;

	return 0;
}

