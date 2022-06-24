#include<iostream>
using namespace std;
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int fq[26] = {0};
    bool check = true;
    for(int i = 0; i < a.length(); i++){
        fq[a[i] - 'A']++;
//        cout << a[i] - 'A' << " " << fq[a[i]-'A'] << endl;
    }
    for(int i = 0; i < b.length(); i++){
        fq[b[i] - 'A']++;
//        cout << b[i] - 'A' << " " << fq[b[i]-'A'] << endl;
    }
    for(int i = 0; i < c.length(); i++){
        if(fq[c[i] - 'A'] > 0){
            fq[c[i] - 'A']--;
        }
        else{
            check  = false;
            break;
        }
    }
    if(check){
        for(int i = 0; i < 26; i++){
            if(fq[i] > 0 || fq[i] < 0){
//                cout << i << " " << fq[i] << endl;
                check = false;
                break;
            }
        }
    }
    if(check){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
