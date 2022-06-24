#include<iostream>
#include<map>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n), dup;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(mp.find(a[i]) == mp.end()){
            dup.push_back(a[i]);
            mp[a[i]]++;
        }
    }
    int t = dup.size();
    cout << t << endl;
    for(int i = t-1; i >= 0; i--){
        cout << dup[i] << " ";
    }
    return 0;
}
