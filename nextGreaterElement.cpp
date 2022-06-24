#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int search(vector<int> &ans, int x){
    for(int i = (int)ans.size()-1; i >= 0; i--){
        if(ans[i] > x){
            return ans[i];
        }
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> ans;
    ans.push_back(-1);
    int mx = INT_MIN;
    for(int i = n-2; i >= 0; i--){
        if(a[i] < a[i+1]){
            mx = max(mx, a[i+1]);
            ans.push_back(a[i+1]);
        }
        else{
            int p = search(ans, a[i]);
            ans.push_back(p);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
    return 0;
}
























/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<ll> st;
    vector<ll> ans(n, -1);
    for(ll i = 0; i < n; i++){
        if(st.empty()){
            st.push(i);
            continue;
        }
        while(!st.empty() && a[st.top()] < a[i]){
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()] = -1;
        st.pop();
    }
    for(ll i = 0; i < n; i++){
        cout << ans[i] << " \n"[i == n-1];
    }
    return 0;
}
*/
