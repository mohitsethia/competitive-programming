#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Player.h"

class Board {
    std::map<Player *, int> playerPos;
    int board;

    public:

    Board(int n): board(n) { 
    }

    int getSize() {
        return this->board;
    }

    void SetPlayers(std::vector<Player*> &players) {
        for(Player *p: players) {
            playerPos[p] = 0;
        }
    }

    void SetNewPos(Player *player, int newPos) {
        playerPos[player] = newPos;
    }

    int getPlayerPos(Player *player) {
        return playerPos[player];
    }

};