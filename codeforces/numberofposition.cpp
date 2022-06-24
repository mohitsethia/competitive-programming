#include<iostream>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    cout << n-(max(a+1, n-b))+1 << "\n";
    return 0;
}
