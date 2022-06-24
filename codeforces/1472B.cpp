#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int one = 0, two = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            one += x == 1;
            two += x == 2;
        }
        if(one%2 || (two%2 && !one)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    return 0;
}
