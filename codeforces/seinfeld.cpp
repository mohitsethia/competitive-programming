#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s;
    cin >> s;
    int cnt = 1;
    while(s[0] != '-'){
        int open_count = 0, min_operations = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '{'){
                open_count++;
            }
            else{
                if(open_count == 0){
                    open_count++;
                    min_operations++;
                }
                else{
                    open_count--;
                }
            }
        }
        min_operations += open_count/2;
        cout << cnt++ << ". " << min_operations << "\n";
        cin >> s;
    }
    return 0;
}
