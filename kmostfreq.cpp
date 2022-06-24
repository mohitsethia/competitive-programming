#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;
void kfreq(int a[], int n, int k){
    vector<int> top(k+1);
    for(int i = 0 ; i < k; i++){
        top[i] = INT_MIN;
    }
    unordered_map<int, int> freq;
    for(int m = 0; m < n; m++){
        freq[a[m]]++;
        top[k] = a[m];
        auto it = find(top.begin(), top.end() -1, a[m]);
        for(int i = distance(top.begin(), it) - 1; i >= 0; i--){
            if(freq[top[i]] < freq[top[i+1]]){
                swap(top[i], top[i+1]);
            }
            else if(freq[top[i]] == freq[top[i+1]] && top[i] >top[i+1]){
                swap(top[i], top[i+1]);
            }
            else{
                break;
            }
        }
        for(int i = 0; i < k && top[i] != INT_MIN; ++i){
            cout << top[i] << " ";
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        kfreq(a, n, k);
        cout << endl;
    }
    return 0;
}
/*
// C++ program to find top k elements in a stream 
#include <iostream>
#include<unordered_map>
#include<vector> 
using namespace std; 

// Function to print top k numbers 
void kTop(int a[], int n, int k) 
{ 
	// vector of size k+1 to store elements 
	vector<int> top(k + 1);     
	   for(int i = 0; i < k; i++){
	       top[i] = INT_MIN;
	   }

	// array to keep track of frequency 
	unordered_map<int, int> freq; 

	// iterate till the end of stream 
	for (int m = 0; m < n; m++) { 
		// increase the frequency 
		freq[a[m]]++; 

		// store that element in top vector 
		top[k] = a[m]; 

		// search in top vector for same element 
		auto it = find(top.begin(), top.end() - 1, a[m]); 

		// iterate from the position of element to zero 
		for (int i = distance(top.begin(), it) - 1; i >= 0; --i) { 
			// compare the frequency and swap if higher 
			// frequency element is stored next to it 
			if (freq[top[i]] < freq[top[i + 1]]) 
				swap(top[i], top[i + 1]); 

			// if frequency is same compare the elements 
			// and swap if next element is high 
			else if ((freq[top[i]] == freq[top[i + 1]]) 
					&& (top[i] > top[i + 1])) 
				swap(top[i], top[i + 1]); 
			else
				break; 
		} 

		// print top k elements 
		for (int i = 0; i < k && top[i] != INT_MIN; ++i) 
			cout << top[i] << ' '; 
	} 
	cout << endl; 
} 

// Driver program to test above function 
int main() 
{ 
    int t;
    cin >> t;
    while(t--){
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
//	int k = 4; 
//	int arr[] = { 5, 2, 1, 3, 0 }; 
//	int n = sizeof(arr) / sizeof(arr[0]); 
	kTop(a, n, k);
} 
	return 0; 
} 
*/
