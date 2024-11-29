#ifndef O_H
#define O_H

#include "Tetromino.h"

class O : public Tetromino {
    private:
    public:
        O();
        void rotate() override;
        Tetromino* clone() const override;
};

#endif