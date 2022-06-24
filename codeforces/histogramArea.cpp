#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int largestRectangleArea(vector<int> &height){
    if(height.size() == 0) return 0;
    int n = height.size();
    vector<int> lessFromLeft(n);
    vector<int> lessFromRight(n);
    lessFromLeft[0] = -1;
    lessFromRight[n-1] = n;
    for(int i = 1; i < n; i++){
        int p = i-1;
        while(p >= 0 && height[p] >= height[i]){
            p = lessFromLeft[p];
        }
        lessFromLeft[i] = p;
    }
    for(int i = n-2; i >= 0; i--){
        int p = i+1;
        while(p < n && height[p] >= height[i]){
            p = lessFromRight[p];
        }
        lessFromRight[i] = p;
    }
    int maxArea = 0;
    for(int i = 0; i < n; i++){
        maxArea = max(maxArea, height[i]*(lessFromRight[i] - lessFromLeft[i]-1));
    }
    return maxArea;
}

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << largestRectangleArea(height) << "\n";
    return 0;
}



















/*
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
#define endl '\n'
typedef long long ll;
int calcArea(vector<int>& arr, int& n){
    stack<int> st;
    int maxArea = -1, i = 0;
    for(i = 0; i < n;){
        if(st.empty() || arr[st.top()] <= arr[i]){
            st.push(i++);
        }
        else{
            int top = st.top();
            st.pop();
            int area;
            if(st.empty()){
                area = arr[top]*i;
            }
            else{
                area = arr[top] * (i-st.top()-1);
            }
            maxArea = max(maxArea, area);
        }
    }
    while(!st.empty()){
        int top = st.top();
        st.pop();
        int area;
        if(st.empty()){
            area = arr[top]*i;
        }
        else{
            area = arr[top] * (i- st.top() -1);
        }
        maxArea = max(maxArea, area);
    }
    return maxArea;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << calcArea(arr, n) << endl;
    return 0;
}
*/
