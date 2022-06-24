#include "SnakeAndLadder.h"
#include <iostream>
#include <algorithm>
#include <vector>

int SnakeAndLadder::getThroughSnakeAndLadder(int pos) {
    int newPos = pos;
    for(Snake *snake: snakes) {
        if(snake->getStart() == newPos) {
            newPos = snake->getEnd();
            break;
        }
    }
    for(Ladder *ladder: ladders) {
        if(ladder->getStart() == newPos) {
            newPos = ladder->getEnd();
            break;
        }
    }
    return newPos;
}

void SnakeAndLadder::StartGame() {
    srand(time(NULL));
    int boardSize = board->getSize();
    while(!PlayersTurn.empty()) {
        Player *player = PlayersTurn.front();
        std::string playerName = player->getName();
        int oldPos = board->getPlayerPos(player);
        PlayersTurn.pop();
        int dice = rand()%6 + 1;
        int newPos = oldPos + dice;
        if(newPos > boardSize) {
            newPos = oldPos;
        }
        else if(newPos < boardSize) {
            newPos = getThroughSnakeAndLadder(newPos);
            board->SetNewPos(player, newPos);
        }
        if(newPos == boardSize) {
            std::cout << "Congrats " << playerName << " has reached the end of the game!" << std::endl;
        }
        else {
            PlayersTurn.push(player);
            std::cout << "New Position of " << playerName << " is " << newPos << std::endl;
        }
    }
}
