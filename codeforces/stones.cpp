#include<iostream>
using namespace std;
int main(){
    int n, count = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n;){
        char ch = s[i];
        int j = i+1;
        for(j = i+1; j < n; j++){
            if(ch == s[j]){
                count++;
            }
            else{
                break;
            }
        }
        i = j;
    }
    cout << count << endl;
    return 0;
}
