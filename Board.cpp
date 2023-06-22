#include "Board.hpp"

Board::Board(){
    for (int i=0;i<home_fields_number;i++){
        for (int y=0;y<player_number;y++){
            pawnFieldId[y][i]=i;
        }
    }
    //pawnFieldId[0][1]=4;
    //pawnFieldId[1][1]=4;
    //pawnFieldId[0][1]=8;

    //movePawnTo(1,1,0);
    //movePawnTo(2,1,4);

    diece.randomizeDiece();
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
    int tmpPawnFieldId=getPawnFieldRealId(player_id, pawn_id);

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

void Board::movePawnTo(int player_id, int pawn_id, int position_real){
    if(position_real<44&&position_real>3){
            removeFieldFlagStatus(pawnFieldId[player_id][pawn_id]);
    }
    else if(position_real>=44&&position_real<48){
            removeFieldMetaFlagStatus(position_real-44,player_id);
    }

    setFieldFlagStatus(4+position_real+player_id*offset_player_fields, player_id, pawn_id);
    //dodac status flagi dla mety
    pawnFieldId[player_id][pawn_id]=position_real+4;
}

void Board::movePawn(int player_id, int pawn_id, short moveDistance){

    int whereIsPawn_tmp=getPawnFieldPersonalId(player_id, pawn_id);
    //std::cerr<<player_id<<pawn_id<<" wychodze z: "<<getPawnFieldRealId(player_id, pawn_id)<<" \t";

    if(whereIsPawn_tmp<4){//baza
        if(moveDistance==6){
            short status=compareFieldWithPlayer(player_id*offset_player_fields, player_id);
            if(status!=1){
                if(status==2){//start zablokowany przez wroga
                    std::cout<<"exit occupied pawn destroyed"<<std::endl;
                    destroyPawn(player_id*offset_player_fields);
                }
                pawnFieldId[player_id][pawn_id]=4;
                setFieldFlagStatus(player_id*offset_player_fields,player_id,pawn_id);
                //std::cout<<"exit home do pola"<<getPawnFieldRealId(player_id, pawn_id)<<std::endl;
            }
            else{//start zablokowany przez sojusznika
                std::cout<<"exit blocked by ally"<<std::endl;
            }


        }
    }
        else{
            if(whereIsPawn_tmp<44-moveDistance){//sciezka
                short field_id_to_compare=pawnFieldId[player_id][pawn_id]+offset_player_fields*player_id-4+moveDistance;
                    if (field_id_to_compare>39)
                        field_id_to_compare-=40;
                short status=compareFieldWithPlayer(field_id_to_compare, player_id);
                std::cout<<"FlagField = "<<field_id_to_compare<<"\t status"<<status<<std::endl;
                if(status!=1){
                    if(status==2){
                        std::cout<<"path occupied pawn destroyed"<<std::endl;
                        destroyPawn(field_id_to_compare);
                    }
                    setFieldFlagStatus(field_id_to_compare, player_id, pawn_id);
                    removeFieldFlagStatus(getPawnFieldRealId(player_id,pawn_id));
                    pawnFieldId[player_id][pawn_id]+=moveDistance;

                }
                else
                {
                    std::cout<<"path blocked by ally"<<std::endl;
                }


            }
            else
            if(whereIsPawn_tmp<48-moveDistance){//meta
                if(fieldMetaFlags[player_id][whereIsPawn_tmp+moveDistance-44].isOccupied==false){
                    fieldMetaFlags[player_id][whereIsPawn_tmp+moveDistance-44].isOccupied=true;
                    removeFieldMetaFlagStatus(whereIsPawn_tmp, player_id);
                    pawnFieldId[player_id][pawn_id]+=moveDistance;
                }
                else{
                }

            }
    }

}

int Board::getPawnFieldRealId(int player_id, int pawn_id){
    int tmp_pawnFieldId=pawnFieldId[player_id][pawn_id];
    if ((tmp_pawnFieldId<fields_number_normal+home_fields_number)&&(tmp_pawnFieldId>=home_fields_number)){
        if (tmp_pawnFieldId+offset_player_fields*player_id>43){
            return tmp_pawnFieldId+offset_player_fields*player_id-fields_number_normal;
        }else{
            return tmp_pawnFieldId+offset_player_fields*player_id;
        }
    }

}

int Board::getPawnFieldPersonalId(int player_id, int pawn_id){
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

void Board::destroyPawn(int flag_field_id){
    pawnFieldId[fieldFlags[flag_field_id].playerId][fieldFlags[flag_field_id].pawnId]=fieldFlags[flag_field_id].pawnId;
    fieldFlags[flag_field_id].isOccupied=false;
    std::cout<<"pawn destroyed on fieldFlag: "<<flag_field_id<<std::endl;
    sound.play_sword();
    //setFieldFlagStatus(getPawnFieldRealId(destroyed_player_id, destroyed_pawn_id), by_player_id, by_pawn_id);
    //pawnFieldId[destroyed_player_id][destroyed_pawn_id]=destroyed_pawn_id;
}

short Board::compareFieldWithPlayer(int field_real_id_to_compare, int compare_with_player_id){
    if(fieldFlags[field_real_id_to_compare].isOccupied==0){
        //std::cout<<"puste"<<field_real_id<<""<<std::endl;//----------------------------------------------------------------------------------------
        return 0;
    }
    else{
            if(fieldFlags[field_real_id_to_compare].playerId==compare_with_player_id){
                return 1;
            }
            else
                return 2;
    }

    //std::cout<<"field "<<field_id<<" is Occupied= "<<fieldFlags[field_id].isOccupied<<std::endl;
}

void Board::setFieldFlagStatus(int flag_field_id, int player_id, int pawn_id){
    fieldFlags[flag_field_id].playerId=player_id;
    fieldFlags[flag_field_id].pawnId=pawn_id;
    fieldFlags[flag_field_id].isOccupied=true;
}

void Board::removeFieldFlagStatus(int field_real_id){
    if (field_real_id>3&&field_real_id<44){
            fieldFlags[field_real_id-4].isOccupied=false;
    }
    else std::cerr<<"nie mozna usunac flagi - pole poza zakresem"<<std::endl;
}

void Board::removeFieldMetaFlagStatus(int field_real_id, int player_id){
    if (field_real_id>43&&field_real_id<48){
            fieldMetaFlags[player_id][field_real_id-44].isOccupied=false;
    }
    else removeFieldFlagStatus(field_real_id);
}

void Board::testFlagStatus(){
    for (int i=0; i<40;i++){
            std::cout<<i<<"("<<i+4<<"): "<<fieldFlags[i].isOccupied<<fieldFlags[i].playerId<<fieldFlags[i].pawnId<<std::endl;;
    }
}


void Board::testMetaFlagStatus(){
    for (int i=0; i<4;i++){
        for (int j=0; j<4;j++){
            std::cout<<fieldMetaFlags[i][j].isOccupied;
        }
        std::cout<<std::endl;
    }
}
