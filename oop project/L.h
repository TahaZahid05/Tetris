#ifndef L_H
#define L_H

#include "Tetromino.h"

class L : public Tetromino {
private:
    int rotationState; 
public:
    L();
    void rotate();
    Tetromino* clone() const override;
};

#endif
