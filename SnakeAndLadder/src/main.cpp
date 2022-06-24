#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include "Snake.h"
#include "Ladder.h"
#include "Player.h"
#include "Board.h"
#include "SnakeAndLadder.h"

int main() {

    SnakeAndLadder *game = new SnakeAndLadder(100);

    int noOfSnakes;
    std::cin >> noOfSnakes;
    std::vector<Snake *> snakes;
    for(int i = 0; i < noOfSnakes; i++) {
        int start, end;
        std::cin >> start >> end;
        Snake *s = new Snake(start, end);
        snakes.push_back(s);
    }

    int noOfLadders;
    std::cin >> noOfLadders;
    std::vector<Ladder *> ladders;
    for(int i = 0; i < noOfLadders; i++) {
        int start, end;
        std::cin >> start >> end;
        Ladder *l = new Ladder(start, end);
        ladders.push_back(l);
    }

    int noOfPlayers;
    std::cin >> noOfPlayers;
    std::vector<Player *> players;
    for(int i = 0; i < noOfPlayers; i++) {
        std::string name;
        std::cin >> name;
        Player *p = new Player(name, i);
        players.push_back(p);
    }

    game->SetSnakes(snakes);
    game->SetLadders(ladders);
    game->SetPlayers(players);
    std::cout << "Game Starting!!" << std::endl;
    game->StartGame();

    return 0;
}