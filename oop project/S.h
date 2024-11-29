#ifndef S_H
#define S_H

#include "Tetromino.h"

class S : public Tetromino {
private:
    int rotationState; // Tracks the current rotation state (0 or 1 for S)
public:
    S();
    void rotate() override; ;
    Tetromino* clone() const override;
};

#endif
