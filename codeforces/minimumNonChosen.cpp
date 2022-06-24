#include <iostream>
#include <vector>
#include<map>
using namespace std;
#define int long long
void printLIS(vector<int>& arr)
{
	for (int x : arr)
		cout << x << " ";
	cout << endl;
}
vector<int> constructPrintLIS(vector<int>& arr, int n)
{
	vector<vector<int> > L(n);

	L[0].push_back(arr[0]);

	for (int i = 1; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if ((arr[i] > arr[j]) &&
					(L[i].size() < L[j].size() + 1))
				L[i] = L[j];
		}

		L[i].push_back(arr[i]);
	}

	vector<int> max = L[0];

	for (vector<int> x : L)
		if (x.size() > max.size())
			max = x;

	//printLIS(max);
    return max;
}

int minimum_nonchosen(int n, vector<int> a){
    vector<int> dp1 = constructPrintLIS(a, n);
    reverse(a.begin(), a.end());
    vector<int> dp2 = constructPrintLIS(a, n);
    map<int, int> visited;
    for(int& i: dp1){
        visited[i]++;
    }
    for(int& i: dp2){
        visited[i]++;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(visited.find(a[i]) == visited.end()){
            cnt++;
        }
    }
    return cnt;
}
int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int j = 0; j < n; j++){
        cin >> a[j];
    }
    int result = minimum_nonchosen(n, a);
    cout << result;
    return 0;
}
