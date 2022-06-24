#include <iostream>
#include<cmath>
using namespace std;
long long int string2number(string s , int i , int length ){
    if(s[i+1] =='\0'){
        return s[i] -'0' ;
    }
    long long int ans= (s[i]-'0')*pow(10, length-(i+1) ) + string2number(s,i+1 , length);

    return ans;
}
int main() {
    string s;
    cin>>s;
    cout<<string2number( s,0 ,s.length() );
    return 0;
}
