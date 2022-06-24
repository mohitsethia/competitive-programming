#include<iostream>
#include<vector>
using namespace std;
bool mycompare(string x, string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<string> v;
        for(int i = 0; i < n; i++){
            string x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end(), mycompare);
        for(auto it : v){
            cout << it;
        }
        cout << endl;
    }
    return 0;
}
