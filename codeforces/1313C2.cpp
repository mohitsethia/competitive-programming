#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n+2);
    stack<ll> st;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    st.push(0);
    vector<ll> left(n+2), right(n+2);
    for(int i = 1; i <= n; i++){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        int t = st.top();
        left[i] = left[t] + a[i]*(i-t);
        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }
    st.push(n+1);
    for(int i = n; i >= 1; i--){
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        int t = st.top();
        right[i] = right[t] + a[i]*(t-i);
        st.push(i);
    }
    ll ans = 0, pos = 0;
    vector<ll> res(n+2);
    for(int i = 1; i <= n; i++){
        ll temp = left[i] + right[i] - a[i];
        if(temp > ans){
            ans = temp;
            pos = i;
        }
    }
    res[pos] = a[pos];
    for(int i = pos-1; i >= 1; i--){
        res[i] = min(a[i], res[i+1]);
    }
    for(int i = pos+1; i <= n; i++){
        res[i] = min(a[i], res[i-1]);
    }
    for(int i = 1; i <= n; i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
