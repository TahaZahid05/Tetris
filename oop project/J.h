#ifndef J_H
#define J_H

#include "Tetromino.h"

class J : public Tetromino {
private:
    int rotationState;
public:
    J();
    void rotate() override;
    Tetromino* clone() const override;
};

#endif
