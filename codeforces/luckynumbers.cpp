#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
bool check(int n){
    int a[8] = {0};
    while(n){
        if(n%10 != 4 && n%10 != 7){
            return false;
        }
        a[n%10]++;
        n /= 10;
    }
    if(a[4] == a[7]){
        return true;
    }
    return false;
}
int32_t main(){
    int n;
    cin >> n;
    if(to_string(n).length() %2){
        int l = to_string(n).length();
        l++;
        for(int i = 0; i < l/2; i++){
            cout << "4";
        }
        for(int i = l/2; i < l; i++){
            cout << "7";
        }
        return 0;
    }
    string s = to_string(n);
    char t = s[0];
    if(t == '8' || t == '9'){
        int l = s.length() + 2;
        for(int i = 0; i < l/2; i++){
            cout << "4";
        }
        for(int i = l/2; i < l; i++){
            cout << "7";
        }
        return 0;
    }
    if(t == '1' || t == '2' || t == '3'){
        int l = s.length();
        for(int i = 0; i < l/2; i++){
            cout << "4";
        }
        for(int i = l/2; i < l; i++){
            cout << "7";
        }
        return 0;
    }   
    else if(t == '4'){
    
    }   
    else if(t == '5' || t == '6'){
        s[0] = '7';
    }   
    else if(t == '7'){
        bool all = true;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '7'){
                all = false;
                break;
            }
        }
        if(all){
            int l = s.length()+2;
            for(int i = 0; i < l/2; i++){
                cout << "4";
            }
            for(int i = l/2; i < l; i++){
                cout << "7";
            }
            return 0;
        }
    }   

    int x = s[0]-'0';
    for(int i = 1; i < s.length(); i++){
        x *= 10;
        x += s[i]-'0';
    }
    for(int i = x; ; i++){
        if(check(i)){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
