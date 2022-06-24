#pragma once
#include <vector>
#include <string>
#include "Player.h"
#include "Board.h"

class TicTacToe {

    Board *board;
    public:

    TicTacToe() {

    }

    void setBoard(int n) {
        board = new Board(n);
    }

    bool isValidMove(int row, int col) {
        return board->isEmpty(row, col);
    }

    void play(Player *player, int row, int col) {
        board->put(player, row, col);
    }

    bool isGameOver();

    bool hasWon(Player *player);

};