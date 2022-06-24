#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, count = 1;
        cin >> n;
        int m[n][n];
        for(int i = 0; i < n; i++){
            //if i is even then traverse in increasing order
            if(i%2 == 0){
                for(int j = 0; j < n; j++){
                    m[i][j] = count;
                    count++;
                }
            }
            else{
                for(int j = n-1; j >= 0; j--){
                    m[i][j] = count;
                    count++;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
