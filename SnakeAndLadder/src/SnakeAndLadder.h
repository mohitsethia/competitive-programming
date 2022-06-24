#pragma once
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"
#include "Board.h"

class SnakeAndLadder {
    std::vector<Snake *> snakes;
    std::vector<Ladder *> ladders;
    std::vector<Player *> players;
    std::queue<Player *> PlayersTurn;
    Board *board;

    public:

    SnakeAndLadder(int n) {
        board = new Board(n);
    }

    void SetSnakes(std::vector<Snake *> &snakes) {
        this->snakes = snakes;
    }

    void SetLadders(std::vector<Ladder *> &ladders) {
        this->ladders = ladders;
    }

    void SetPlayers(std::vector<Player *> &players) {
        this->players = players;
        board->SetPlayers(players);
        for(Player *p: players) {
            PlayersTurn.push(p);
        }
    }

    void StartGame();

    int getThroughSnakeAndLadder(int pos);

};