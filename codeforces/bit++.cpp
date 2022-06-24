#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "++X" || s == "X++"){
            cnt1++;
        }
        if(s == "--X" || s == "X--"){
            cnt2++;
        }
    }
    cout << cnt1-cnt2 << endl;
    return 0;
}
