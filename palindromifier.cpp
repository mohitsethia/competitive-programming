#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int n = s.length();
    printf("3\nR %d\n", n-1);
    printf("L %d\nL 2", n);
    return 0;
}
