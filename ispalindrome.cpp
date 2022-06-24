#include<iostream>
#include<string>
using namespace std;
bool ispalindrome(int *a, int i, int j){
    if(i == j/2){
        cout << "true";
        return true;
    }
    if(a[i] != a[j - i]){
        cout << "false";
        return false;
    }
    ispalindrome(a, i+1, j);
}
int main(){
    int n;
    cin >> n;   
    int a[n], i = 0, j = n-1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int x = ispalindrome(a, i, j);
    return 0;
}
