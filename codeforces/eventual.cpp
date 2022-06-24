#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<char, int> mp;
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
        }
        int flag = 1;
        for(auto i : mp){
            if(i.second % 2 != 0){
                flag = 0;
                break;
            }
        }
        if(!flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
