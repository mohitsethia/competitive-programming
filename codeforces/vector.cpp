#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    vector<int> v[2];
    int x, y;
    cin >> x >> y;
    v.push_back(x);
    v.push_back(y);
    for(auto i : v){
        cout << v[i];
    } 
    return 0;
}
