#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        printf("%c", 'a'+(i%4));
    }
    return 0;
}
