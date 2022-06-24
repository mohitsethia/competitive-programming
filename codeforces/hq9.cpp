#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int main(){
    string s;
    cin >> s;
    int flag = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
            flag = 1;
            break;
        }
        else{
            if(s[i] == '+'){
                s[i] += 1;
            }
            if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}
