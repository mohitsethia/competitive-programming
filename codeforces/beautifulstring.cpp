#include<iostream>
#include<cstring>

using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        string a;
        int i, count = 0;
        cin >> a;
        int l = a.length();
        for(i = 0; i < l - 1; i++){
            if(i == 0 && a[i] == '?'){
                if(a[i + 1] == 'b' || a[i + 1] == 'c' || a[i+1] == '?')
                    a[i] = 'a';
                else if(a[i + 1] == 'a' || a[i + 1] == 'b' || a[i + 1] == '?')
                    a[i] = 'c';
                else
                    a[i] = 'b';
            }
            if(a[i] != '?' && a[i] == a[i+1]){
                cout << "-1" << endl;
                count = 1;
                break;
            }
            else{
                if(a[i] == '?'){
                    if((a[i - 1] == 'a' || a[i - 1] == 'b') && (a[i + 1] == 'b' || a[i + 1] == 'a' || a[i + 1] == '?')){
                        a[i] = 'c';
                    }
                    else if((a[i - 1] == 'a' || a[i - 1] == 'c') && (a[i + 1] == 'c' || a[i + 1] == 'a' || a[i + 1] == '?')){
                        a[i] = 'b';
                    }
                    else if((a[i - 1] == 'b' || a[i - 1] == 'c') && (a[i + 1] == 'c' || a[i + 1] == 'b' || a[i + 1] == '?')){
                        a[i] = 'a';
                    }
                }
            }
        }
        if(a[i] == '?'){
            if(a[i - 1] == 'c')
                a[i] = 'b';
            else if(a[i-1] == 'b')
                a[i] = 'a';
            else
                a[i] = 'c';
        }
        if(count == 0){
            cout << a << endl;
        }
    }
    return 0;
}
