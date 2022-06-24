#include<iostream>
using namespace std;
int cnt = 0;
bool isSafe(int board[][10], int i, int j, int n){
    for(int row = 0; row < i; row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }
    x = i;
    y = j;
    while(x >= 0 && y < n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveNQueen(int board[][10], int i, int n){
    if(i == n){
        cnt++;
        for(i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        cout << cnt << endl << endl;
        return false;
    }
    for(int j = 0; j < n; j++){
        if(isSafe(board, i, j, n)){
            board[i][j] = 1;
            bool nextQueen = solveNQueen(board, i+1, n);
            if(nextQueen){
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int board[10][10] = {0};
    if(solveNQueen(board, 0, n) == false){
        if(cnt == 0)
            cout << "-1";
    }
    return 0;
}
