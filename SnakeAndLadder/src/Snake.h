#pragma once

class Snake {
    int startPos, endPos;

    public:

    Snake() {

    }

    Snake(int start, int end) {
        this->startPos = start;
        this->endPos = end;
    }

    int getStart() {
        return this->startPos;
    }

    int getEnd() {
        return this->endPos;
    }

};