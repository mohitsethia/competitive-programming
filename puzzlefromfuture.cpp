#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string b, a = "";
        cin >> n >> b;
        for(int i = 0; i < n; i++){
            a += '1';
        }
        for(int i = 1; i < n; i++){
            if(b[i] == '1'){
                if(b[i-1] == '1'){
                    if(a[i-1] == '1'){
                        a[i] = '0';
                    }
                    else{
                        a[i] = '1';
                    }
                }
                else{
                    a[i] = '1';
                }
            }
            else{
                if(b[i-1] == '0'){
                    if(a[i-1] == '0'){
                        a[i] = '1';
                    }
                    else{
                        a[i] = '0';
                    }
                }
                else{
                    if(a[i-1] == '0'){
                        a[i] = '0';
                    }
                    else{
                        a[i] = '1';
                    }
                }
            }
        }
        cout << a << endl;
    }
    return 0;
}
