#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void solve() {
	int n;
	cin >> n;
	int a[n], dp[n];
	for(int i = 0; i < n; i++){
		char c;
        cin >> c;
        a[i] = c-'0';
	}
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] >= a[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j]+1;
			}
		}
	}
	cout << (n- *max_element(dp, dp+n)) << endl;
	return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n >> s;
    int maxCount = 0, cnt = 0;
    for(int i = 1; i < n; i++){
        if(s[i] >= s[i-1]){
            cnt++;
        }
        else{
            if(cnt){
                maxCount = max(maxCount, cnt+1);
            }
            cnt = 0;
        }
    }
    maxCount = max(maxCount, cnt+1);
    cout << s.length() - maxCount << endl;
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
*/
