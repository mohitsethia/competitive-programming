#include<iostream>
#include<map>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    map<string, string> word;
    for(int i = 0; i < m; i++){
        string a, b;
        cin >> a >> b;
        word[a] = b;
    }
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        string b = word[a];
        cout << ((a.length() <= b.length()) ? a : b) << endl;
    }
    return 0;
}
