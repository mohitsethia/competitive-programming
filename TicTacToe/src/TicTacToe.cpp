#include "TicTacToe.h"

bool TicTacToe::isGameOver() {
    return board->isFull();
}

bool TicTacToe::hasWon(Player *player) {
    int n = board->getSize();
    int diagonal = 0, antiDiagonal = 0;
    for(int i = 0; i < n; i++) {
        int row = 0, col = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) {
                diagonal += player->getSign() == board->getChar(i, j);
            }
            else{
                col += player->getSign() == board->getChar(i, j);
            }
        }
        for(int j = 0; j < n; j++) {
            row += player->getSign() == board->getChar(i, j);
        }
        if(row == n || col == n || diagonal == n) return true;
    }
    for(int i = 0, j = n-1; i < n && j >= 0; i++, j--) {
        antiDiagonal += player->getSign() == board->getChar(i, j);
    }
    return antiDiagonal == n;
}