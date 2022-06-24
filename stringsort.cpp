#include<iostream>
#include<algorithm>
using namespace std;
bool mycompare(string a, string b){
    if(a.find(b) == 0 || b.find(a) == 0){
        return a.length() > b.length();
    }
    return a < b;
}
int main(){
    int t;
    cin >> t;
    string c[t];
    for(int i = 0; i < t; i++){
        cin >> c[i];
    }
    sort(c, c+t, mycompare);
    for(int i = 0; i < t; i++){
        cout << c[i] << endl;
    }
    return 0;
}
