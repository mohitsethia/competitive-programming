#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m[3][3], sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> m[i][j];
            sum += m[i][j];
        }   
    }
    sum /= 2;
    m[0][0] = sum - m[0][1] - m[0][2];
    m[1][1] = sum - m[1][0] - m[1][2];
    m[2][2] = sum - m[2][0] - m[2][1];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
