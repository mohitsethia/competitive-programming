#include<iostream>
#include<cstring>
using namespace std;
int main() {
char s;
cin >> s;
if(s>='a' && s<='z'){
  cout << "lowercase";
  }
  else if(s>='A' && s<='Z'){
  cout << "UPPERCASE";
  }
  else{
    cout << "Invalid";
  }
	return 0;
}
