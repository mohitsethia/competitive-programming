#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include "TicTacToe.h"
#include "Player.h"

int main() {

    int boardSize;
    std::cin >> boardSize;

    TicTacToe *game = new TicTacToe;
    std::vector<Player *> players;

    game->setBoard(boardSize);

    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    std::queue<Player *> PlayersTurn;

    for(int i = 0; i < numberOfPlayers; i++) {
        std::string name;
        char sign;
        std::cin >> name >> sign;
        Player *player = new Player(name, sign);
        players.push_back(player);
        PlayersTurn.push(player);
    }

    bool gameOver = true;

    while(!game->isGameOver()) {
        int row, col;
        std::cin >> row >> col;
        row--, col--;
        Player *player = PlayersTurn.front();
        if(!game->isValidMove(row, col)) {
            std::cout << "Invalid Move" << std::endl;
            continue;
        }
        game->play(player, row, col);
        if(game->hasWon(player)) {
            std::cout << player->getName() << " has Won!" << std::endl;
            gameOver = false;
            break;
        }
        PlayersTurn.pop();
        PlayersTurn.push(player);
    }

    if(gameOver) {
        std::cout << "Game Over" << std::endl;
    }

    return 0;
}