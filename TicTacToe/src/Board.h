#pragma once
#include <vector>
#include "Player.h"

class Board {

    std::vector<std::vector<char>> board;

    public:

    Board(int n) {
        board = std::vector<std::vector<char>>(n, std::vector<char>(n, '.'));
    }

    char getChar(int row, int col) {
        return board[row][col];
    }

    int getSize() {
        return board.size();
    }

    bool isEmpty(int row, int col) {
        return board[row][col] == '.';
    }

    void put(Player *player, int row, int col) {
        board[row][col] = player->getSign();
    }

    bool isFull() {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board.size(); j++) {
                if(board[i][j] == '.') return false;
            }
        }
        return true;
    }

};