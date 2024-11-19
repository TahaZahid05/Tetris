#ifndef T_H
#define T_H

#include "Tetromino.h"

class T : public Tetromino {
private:
    int rotationState;
public:
    T();
    void rotate();
    Tetromino* clone() const override;
};

#endif
