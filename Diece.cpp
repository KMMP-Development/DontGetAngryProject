#include "Diece.hpp"

Diece::Diece(){
    srand (time(NULL));
}

void Diece::randomizeDiece(){
    number = rand()%6;
    rectangle = rand()%360;
    position_x_offset = 25+rand()%50;
    position_y_offset = 25+rand()%50;
}

short Diece::checkDiece(){
    return number;
}

void Diece::lockDiece(){
    number=0;
}

short Diece::getRandomizeRect(){
    return rectangle;
}

short Diece::getRandomizePos_x(){
    return position_x_offset;
}

short Diece::getRandomizePos_y(){
    return position_y_offset;
}
