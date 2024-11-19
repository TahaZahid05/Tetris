#ifndef I_H
#define I_H

#include "Tetromino.h"

class I : public Tetromino {
    private:
        int rotationState;
    public:
        I();
        void rotate();
        Tetromino* clone() const override;
};

#endif