#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

#define int long long

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int sum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++){
		if(i+1 < a[i]){
			flag = true;
			break;
		}
		sum += (i+1-a[i]);
	}
	if(flag){
		cout << "Second\n";
		return;
	}
	if(sum % 2){
		cout << "First\n";
	}
	else{
		cout << "Second\n";
	}
}

int32_t main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}