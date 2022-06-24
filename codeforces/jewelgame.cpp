#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int count = 0;
        for(int i = 0; i < s.length() - 1;){
            if(s[i] == s[i+1]){
//                cout << s[i] << " " << s[i+1] << " ";
                s.erase(i, 2);
//                cout << s << endl;
                count++;
                if(s.length() == 0){
                    break;
                }
                i-=2;
                if(i < 0){
                    i = 0;
                }
            }
            else{
                i++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
