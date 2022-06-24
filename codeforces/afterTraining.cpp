#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    while(n){
        int i = (m+1)/2;
        int j = i+1;
        if(m%2){
            cout << i << "\n";
            i--;
            n--;
        }
        while(n > 0 && i > 0 && j < m+1){
            if(n == 1){
                cout << i << "\n";
                n--;
            }
            else{
                cout << i << "\n" << j << "\n";
                n -= 2;
                i--;
                j++;
            }
        }
    }
    return 0;
}
