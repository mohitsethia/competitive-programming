#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];	
	}
	vector<int> bit(35, 0);
	for(int i = 0; i < n; i++){
		int x = __builtin_popcount(a[i]);
		bit[x]++;
	}
	int start_bit = __builtin_popcount(a[0]);
    int ans = bit[start_bit];
	for(int i = start_bit-1; i >= 0; i--){
		if(bit[i] > 0){
			ans += bit[i];	
		}
		else{
			break;	
		}
	}
	for(int i = start_bit+1; i < 35; i++){
		if(bit[i] > 0){
			ans += bit[i];	
		}
		else{
			break;	
		}
	}
	cout << ans << endl;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();	
	}
	return 0;	
}
