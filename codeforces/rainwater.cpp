#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;
class Solution{
public:
    ll trappedWater(vector<ll> &bars){
        stack<ll> st;
        ll ans = 0;
        for(ll i = 0; i < (ll)bars.size(); i++){
            while(!st.empty() && bars[st.top()] < bars[i]){
                ll popped_height = bars[st.top()];
                st.pop();
                if(st.empty()) break;
                ll min_height = min(bars[st.top()], bars[i])-popped_height;
                ll distance = i-st.top()-1;
                ans += min_height*distance;
            }
            st.push(i);
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> bars(n);
    for(ll i = 0; i < n; i++){
        cin >> bars[i];
    }
    Solution ans;
    cout << ans.trappedWater(bars) << "\n";
    return 0;
}






















/*
#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n], i, b[n], c[n], sum = 0;
	for(i = 0; i < n; i++){
		cin >> a[i];
		b[i] = 0;
		c[i] = 0;
	}
	b[0] = a[0];
	for(i = 1; i < n; i++){
		if(b[i-1] < a[i]){
			b[i] = a[i];
		}
		else
			b[i] = b[i - 1];
	}
	c[n-1] = a[n-1];
	for(i = n-2; i >= 0; i--){
		if(c[i+1] < a[i]){
			c[i] = a[i];
		}
		else
			c[i] = c[i + 1];
	}
	for(i = 0; i < n; i++){
		sum += (min(b[i], c[i]) - a[i]);
	}
	cout << sum << endl;
	return 0;
}
*/
