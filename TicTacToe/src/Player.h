#pragma once
#include <string>

class Player {
    std::string name;
    char sign;

public:

    Player(std::string name, char sign) {
        this->name = name;
        this->sign = sign;
    }

    std::string getName() {
        return this->name;
    }

    char getSign() {
        return this->sign;
    }

};