#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    int sum = (7-a)+(7-b)+(7-c);
    cout << sum << endl;
    return 0;
}
