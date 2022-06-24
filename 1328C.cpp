#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        string a(n, '0'), b(n, '0');
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                a[i] = '1';
                b[i] = '0';
                for(int j = i+1; j < n; j++){
                    b[j] = s[j];
                }
                break;
            }
            else{
                a[i] = b[i] = (s[i] == '0') ? '0' : '1';
            }
        }
        cout << a << "\n" << b << "\n";
    }
    return 0;
}
