#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int k, len, i;
        cin >> k;
        len = s.length();
        char arr[len+1];
        for(i = 0; i < len; i++){
            if(k > 0){
                if(s[i] == '0'){
                    arr[i] = '1';
                    k--;
                }
                else{
                    arr[i] = '0';
                }
            }
            else{
                arr[i] = '0';
            }
        }
        arr[i] = '\0';
        cout << arr << endl;
    }
    return 0;
}
