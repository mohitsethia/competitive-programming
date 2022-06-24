#include<iostream>
#include<cstring>
using namespace std;
int stringtoint(char *a, int n){
    if(n == 0){
        return 0;
    }
    int digit = a[n-1] -'0';
    int smallans = stringtoint(a, n-1);
    return smallans*10 + digit;
}
int main(){
    char a[1000];
    cin >> a;
    int len = strlen(a);
    cout << stringtoint(a, len);
    return 0;
}
