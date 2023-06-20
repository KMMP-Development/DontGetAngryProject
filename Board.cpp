#include "Board.hpp"

Board::Board(){
    for (int i=0;i<home_fields_number;i++){
        for (int y=0;y<player_number;y++){
            pawnFieldId[y][i]=i;
        }
    }

}

std::pair<int, int> Board::getCoordField(int id){
    return coordField[id];
}

std::pair<int, int> Board::getCoordFieldHome(int player_id, int base_id){
    return coordFieldHome[player_id][base_id];
}

std::pair<int, int> Board::getCoordFieldStart(int player_id){
    return coordFieldStart[player_id];
}

std::pair<int, int> Board::getCoordFieldMeta(int player_id, int meta_id){
    return coordFieldMeta[player_id][meta_id];
}

std::pair<int, int> Board::getCoordPawn(int player_id, int pawn_id){
    int tmpPawnFieldId=getPawnFieldPersonalId(player_id, pawn_id);

    if (tmpPawnFieldId<44){
        if (tmpPawnFieldId>=4){
            return getCoordField(tmpPawnFieldId - home_fields_number);
        }
        else{
            return getCoordFieldHome(player_id, tmpPawnFieldId);
        }
    }
    else{
        return getCoordFieldMeta(player_id, tmpPawnFieldId - 44);
    }

}

void Board::movePawn(int player_id, int pawn_id){
    int* wsk_pawnFieldId=&pawnFieldId[player_id][pawn_id];
    if (*wsk_pawnFieldId<47)
        *wsk_pawnFieldId=*wsk_pawnFieldId+1;
    if (*wsk_pawnFieldId<4)
        *wsk_pawnFieldId=4;
}

void Board::movePawn(int player_id, int pawn_id, short moveDistance){
    for (int i=0; i<=moveDistance; i++){
        movePawn(player_id, pawn_id);
    }
}

int Board::getPawnFieldPersonalId(int player_id, int pawn_id){
    int tmp_pawnFieldId=pawnFieldId[player_id][pawn_id];
    if ((tmp_pawnFieldId<fields_number_normal+home_fields_number)&&(tmp_pawnFieldId>=home_fields_number)){
        if (tmp_pawnFieldId+offset_player_fields*player_id>43){
            return tmp_pawnFieldId+offset_player_fields*player_id-fields_number_normal;
        }else{
            return tmp_pawnFieldId+offset_player_fields*player_id;
        }
    }

}

int Board::getPawnFieldRealId(int player_id, int pawn_id){
    return pawnFieldId[player_id][pawn_id];
}


short Board::throwDiece(){
    diece.randomizeDiece();
    return diece.checkDiece();
}

short Board::checkDiece(){
    return diece.checkDiece();
}

std::pair<short, short> Board::checkDieceCoord(){
    return std::make_pair(diece.getRandomizePos_x(), diece.getRandomizePos_y());
}

short Board::checkDieceRotation(){
    return diece.getRandomizeRect();
}

void Board::randomizeDiece(){
    diece.randomizeDiece();
}

short Board::getPlayerTurn(){
    return playerTurn;
}

void Board::nextPlayerTurn(){
    playerTurn=playerTurn+1;
    if (playerTurn>3)
        playerTurn=0;
}


//void Board::selectPawnAction();

/*void Board::checkPawnMoveAvailbility(){

}
*/
