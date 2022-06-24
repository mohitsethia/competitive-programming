#include<iostream>
using namespace std;
void functioncase(char a){
    if(a >= 'a' && a <= 'z'){
        cout << "L";
    }
    else if(a >= 'A' && a <= 'Z'){
        cout << "U";
    }
    else
        cout << "I";
}
int main(){
    char a;
    cin >> a;
    functioncase(a);
}
