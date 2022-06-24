#pragma once

class Ladder {
    int startPos, endPos;

    public:

    Ladder() {}

    Ladder(int start, int end) {
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