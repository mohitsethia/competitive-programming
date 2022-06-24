#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string , int> mp;
    int n, x;
    string s;
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> s >> x;
        mp.insert(make_pair(s, x));
    }
    for(auto it:mp){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
