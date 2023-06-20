#ifndef BOARD_HPP
#define BOARD_HPP
#include <vector>
#include "Diece.hpp"

#define fields_number_normal 40
#define offset_player_fields 10
#define home_fields_number 4
#define player_number 4

class Board
{
    public:
        Board();
        std::pair<int, int> getCoordField(int id);//wspolrzedne pola sciezki (wspolne)
        std::pair<int, int> getCoordFieldHome(int player_id, int base_id);//wspolrzedne pola bazy (pola gdzie na poczatku sa pionki)
        std::pair<int, int> getCoordFieldStart(int player_id);//wspolrzedne pola startu (gdzie pojawi sie pionek wychodzac z bazy)
        std::pair<int, int> getCoordFieldMeta(int player_id, int meta_id);//wspolrzedne pola mety
        std::pair<int, int> getCoordPawn(int player_id, int pawn_id);//wspolrzedne pionka
        void movePawn(int player_id, int pawn_id);// przesuniecie pionka
        void movePawn(int player_id, int pawn_id, short moveDistance);// przesuniecie pionka
        int getPawnFieldPersonalId(int player_id, int pawn_id);//zwraca id pola (wspolne id zmniejszone o pole startowe gracza)
        int getPawnFieldRealId(int player_id, int pawn_id);//zwraca id pola (pole ma id bez wzgledu na numer gracza)
        short throwDiece();//losuje i zwraca liczbe (0-5)
        short checkDiece();//tylko zwraca liczbe (0-5)
        std::pair<short, short> checkDieceCoord();//zwraca przesuniecie kostki
        short checkDieceRotation();//zwraca obrot kosci
        void randomizeDiece();//losuje liczbe, kat i pozycje kosci
        short getPlayerTurn();
        void nextPlayerTurn();
    private:
        std::pair<int, int> coordField[fields_number_normal]={{0,4},{1,4},{2,4},{3,4},{4,4},{4,3},{4,2},{4,1},{4,0},{5,0}
                                                        ,{6,0},{6,1},{6,2},{6,3},{6,4},{7,4},{8,4},{9,4},{10,4},{10,5}
                                                        ,{10,6},{9,6},{8,6},{7,6},{6,6},{6,7},{6,8},{6,9},{6,10},{5,10}
                                                        ,{4,10},{4,9},{4,8},{4,7},{4,6},{3,6},{2,6},{1,6},{0,6},{0,5}};
        std::pair<int, int> coordFieldHome[4][4] = {{{0,0},{1,0},{0,1},{1,1}}         //lewy gorny nr 0 czerwony
                                                ,{{9,0},{10,0},{9,1},{10,1}}    //prawy gorny nr 1 niebieski
                                                ,{{9,9},{10,9},{9,10},{10,10}}//prawy dolny nr 2 zielony
                                                ,{{0,9},{1,9},{0,10},{1,10}}};   //lewy dolny nr 3 zolty

        std::pair<int, int> coordFieldStart[4] =    {{0,4},{6,0},{10,6},{4,10}};
        std::pair<int, int> coordFieldMeta[4][4] =  {{{1,5},{2,5},{3,5},{4,5}}
                                                    ,{{5,1},{5,2},{5,3},{5,4}}
                                                    ,{{9,5},{8,5},{7,5},{6,5}}
                                                    ,{{5,9},{5,8},{5,7},{5,6}}};
        int pawnFieldId[4][4];
        Diece diece;
        short playerTurn=0;
};

#endif // INPUTMANAGER_HPP

