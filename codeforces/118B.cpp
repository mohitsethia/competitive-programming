#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int spaces = 2*n;
    int cnt = 0;
    for(int i = 0; i <= n; i++){
        for(int s = 0; s < spaces; s++) cout << " ";
        spaces -= 2;
        for(int j = 0; j < cnt; j++){
            cout << j << " ";
        }
        for(int j = cnt; j > 0; j--) cout << j << " ";
        cout << "0\n";
        cnt++;
    }
    cnt -= 2;
    spaces = 2;
    for(int i = 1; i <= n; i++){
        for(int s = 0; s < spaces; s++) cout << " ";
        spaces += 2;
        for(int j = 0; j < cnt; j++) cout << j << " ";
        for(int j = cnt; j > 0; j--) cout << j << " ";
        cout << "0\n";
        cnt--;
    }
    return 0;
}
