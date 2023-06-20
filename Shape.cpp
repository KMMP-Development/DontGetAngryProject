#include "Shape.hpp"

ShapeClass::ShapeClass(Board& board):board(board) {
    rect.setSize(sf::Vector2f(40*scale/50, 40*scale/50));
    rect.setFillColor(sf::Color(200,200,200,100));
    circle.setRadius(20*scale/50);

    playerVisual[0].color=sf::Color(200,80,80,200);//czerwony
    playerVisual[1].color=sf::Color(80,80,210,200);//niebieski
    playerVisual[2].color=sf::Color(80,200,150,200);//zielony
    playerVisual[3].color=sf::Color(180,180,0,200);//zolty
}

void ShapeClass::drawShapes(sf::RenderWindow& window) {
    // Load a sprite to display

    sf::Texture texture;
    texture.loadFromFile("background.jpg");
    sf::Sprite background(texture);
    window.draw(background);

    //pola
    rect.setFillColor(sf::Color(200,200,200,100));

    for (int i=0; i<fields_number_normal; i++) {
        rect.setPosition(board.getCoordField(i).first*scale+x_offset,board.getCoordField(i).second*scale+y_offset);
        window.draw(rect);
    }
        //----------------------------------------------------------------------------------------------------------------------------------------!!!!!!!!!!!!!!!!!!!!!!!!!
    //pola startowe i mety
    for (int i=0;i<4;i++){
        rect.setFillColor(playerVisual[i].color);
        for (int j=0;j<4;j++){
            rect.setPosition(board.getCoordFieldHome(i,j).first*scale+x_offset,board.getCoordFieldHome(i,j).second*scale+y_offset);
            window.draw(rect);
        }

        for (int j=0;j<4;j++){
            rect.setPosition(board.getCoordFieldMeta(i,j).first*scale+x_offset,board.getCoordFieldMeta(i,j).second*scale+y_offset);
            window.draw(rect);
        }
        circle.setFillColor(playerVisual[i].color);
        circle.setPosition(board.getCoordFieldStart(i).first*scale+x_offset,board.getCoordFieldStart(i).second*scale+y_offset);
        window.draw(circle);
    }



        //pionki i kursory
    for (int i=0;i<player_number;i++){
        std::string filename="pionek"+std::to_string(i)+".png";
        playerVisual[i].pawn_texture.loadFromFile(filename);
        playerVisual[i].pawn_sprite.setTexture(playerVisual[i].pawn_texture);
        playerVisual[i].pawn_sprite.setScale(sf::Vector2f(0.26f*scale/50, 0.26f*scale/50));


        for (int j=0; j<4;j++){
            //player[i].pawn_sprite.setPosition(player[i].coords_home[j].first*scale+x_offset-10, player[i].coords_home[j].second*scale+y_offset-65);
            playerVisual[i].pawn_sprite.setPosition(board.getCoordPawn(i,j).first*scale+x_offset+pawn_x_offset, board.getCoordPawn(i,j).second*scale+x_offset+pawn_y_offset);
            window.draw(playerVisual[i].pawn_sprite);

        }
    }
}

float ShapeClass::getScale(){
    return scale;
}

int ShapeClass::getPawn_x_offset(){
    return pawn_x_offset;
}

int ShapeClass::getPawn_y_offset(){
    return pawn_y_offset;
}
