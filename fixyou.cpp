#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        char x;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> x;
                if(i == n-1 && x == 'D'){
                    cnt++;
                }
                if(j == m-1 && x == 'R'){
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
