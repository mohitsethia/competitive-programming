#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        bool flag = true;
        for(int i = 0; i < a.length(); i++){
            if(a[i] == c[i] || b[i] == c[i]){
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
