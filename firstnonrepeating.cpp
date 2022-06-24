#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
int main(){
    queue<char> q;
    unordered_map<char,int> mp;
    char ch;
    cin >> ch;
    while(ch != '.'){
        q.push(ch);
        mp[ch]++;   
        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }
            else{
                cout << q.front() << endl;
                break;
            }
        }
        if(q.empty()){
            cout << "-1" << endl;
        }
        cin >> ch;
    }
    return 0;
}
