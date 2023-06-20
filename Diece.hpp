#ifndef DIECE_HPP
#define DIECE_HPP
#include <stdlib.h>
#include <time.h>


class Diece{

    public:
        Diece();
        void randomizeDiece();
        short checkDiece();
        void lockDiece();
        short getRandomizeRect();
        short getRandomizePos_x();
        short getRandomizePos_y();
    private:
        short number=0;
        short rectangle=0;
        short position_x_offset=0;
        short position_y_offset=0;
};



#endif
