#pragma once

class Player {
    std::string name;
    int Id;

    public:

    Player() {

    }

    Player(std::string name, int id) {
        this->name = name;
        this->Id = id;
    }

    std::string getName() {
        return this->name;
    }

    int getId() {
        return this->Id;
    }
};