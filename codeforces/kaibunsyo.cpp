#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
bool isPalindrome(vector<int>& a){
    int n = (int)a.size();
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n-i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(isPalindrome(a)){
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    map<int, int> mp;
    for(int i = 0; i < n/2; i++){
        if(a[i] != a[n-i-1]){
            if(a[i] != a[n-i-1]){
                mp[a[i]] = a[n-i-1];
                a[i] = a[n-i-1];
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
