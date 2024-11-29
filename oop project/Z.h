#ifndef Z_H
#define Z_H

#include "Tetromino.h"

class Z : public Tetromino {
private:
    int rotationState; // Tracks the current rotation state (0 or 1 for Z)
public:
    Z();
    void rotate() override;
    Tetromino* clone() const override;
};

#endif
