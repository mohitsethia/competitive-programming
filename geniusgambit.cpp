#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#define int long long
using namespace std;
int32_t main(){
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 0){
        cout << "Yes\n";
        for(int i = 0; i < b; i++){
            cout << 1;
        }
        for(int i = 0; i < a; i++){
            cout << 0;
        }
        cout << "\n";
        for(int i = 0; i < b; i++){
            cout << 1;
        }
        for(int i = 0; i < a; i++){
            cout << 0;
        }
        cout << "\n";
    }
    else if(a == 0 || b == 1 || k > a+b-2){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        string s(a+b, '0'), t(a+b, '0');
        s[0] = '1';
        t[0] = '1';
        t[a+b-1] = '1';
        int ind = a+b-1-k;
        s[ind] = '1';
        b -= 2;
        for(int i = 1; i < a+b, b > 0; i++){
            if(s[i] == '0' && t[i] == '0'){
                b--;
                s[i] = t[i] = '1';
            }
        }
        cout << s << endl << t;
    }
    return 0;
}
