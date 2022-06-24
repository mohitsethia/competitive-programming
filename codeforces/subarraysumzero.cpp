//Longest subarray with sum zero
#include<iostream>
#include<unordered_map>
using namespace std;
int longestarray(int *a, int n){
    unordered_map<int, int> mp;
    int pre = 0, len = 0;
    for(int i = 0; i < n; i++){
        pre += a[i];
        if(a[i] == 0 and len == 0){
            len = 1;
        }
        if(pre == 0){
            len = max(len, i+1);
        }
        if(mp.find(pre) != mp.end()){
            len = max(len, i - mp[pre]);
        }
        else{
            mp[pre] = i;
        }
    }
    return len;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << longestarray(a, n);
    return 0;
}
