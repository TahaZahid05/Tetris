#ifndef T_H
#define T_H

#include "Tetromino.h"

class T : public Tetromino {
private:
    int rotationState;
public:
    T();
    void rotate() override;
    Tetromino* clone() const override;
};

#endif
