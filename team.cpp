#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            count++;
        }
        if(b == 1){
            count++;
        }
        if(c == 1){
            count++;
        }
        if(count > 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
