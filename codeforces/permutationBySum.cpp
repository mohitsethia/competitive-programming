#include<iostream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
bool isPossible(int len, int last_max, int s){
    int c = last_max, d = 1;
    int mx = 0, mn = 0;
    for(int i = 0; i < len; i++){
        mx += c;
        mn += d;
        c--;
        d++;
    }
    if(s < mn || s > mx){
        return false;
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int len = r-l+1;
        if(!isPossible(len, n, s)){
            cout << "-1" << endl;
            continue;
        }
        map<int, int> mp;
        vector<int> v, v1;
        for(int i = n; i > 0; i--){
            if(s-i >= 0 && isPossible(len-1, i-1, s-i)){
                s -= i;
                v.push_back(i);
                mp[i]++;
                len--;
            }
            if(s == 0){
                break;
            }
        }
        if(s != 0){
            cout << "-1" << endl;
            continue;
        }
        int j = 0;
        for(int i = 1; i <= n; i++){
            if(mp.find(i) == mp.end()){
                v1.push_back(i);
            }
        }
        for(int i = 1; i < l; i++){
            cout << v1[j++] << " ";
        }
        for(int& it: v){
            cout << it << " ";
        }
        for(int i = r+1; i <= n; i++){
            cout << v1[j++] << " ";
        }
        cout << endl;
    }
    return 0;
}
