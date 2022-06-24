#include<iostream>
#include<algorithm>
using namespace std;
bool mycompare(pair<string, int> a, pair<string, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second > b.second;
    }
}
int main(){
    int amount;
    cin >> amount;
    int n;
    cin >> n;
    pair<string, int> a[n];
    for(int i = 0; i < n; i++){
        string s;
        int salary;
        cin >> s >> salary;
        a[i].first = s;
        a[i].second = salary;
    }
    sort(a, a+n, mycompare); 
    for(int i = 0; i < n; i++){
        if(a[i].second >= amount){
            cout << a[i].first << " " << a[i].second << endl;
        }
    }
    return 0;
}
