#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char s[n], a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
            for(int i = n-1; i >= 0; i--){
                if(s[i] == '2'){
                    a[i] = '1';
                    b[i] = '1';
                }
                else if(s[i] == '1'){
                    if(a > b){
                        b[i] = '1';
                        a[i] = '0';
                    }
                    else{
                        b[i] = '0';
                        a[i] = '1';
                    }
                }
                else{
                    a[i] = '0';
                    b[i] = '0';
                }
            }
        b[n] = '\0';
        a[n] = '\0';
        cout << a << endl;
        cout << b << endl;
        
    }
    return 0;
}   
