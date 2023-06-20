#include "menu.hpp"

MenuClass::MenuClass(Board& board, ShapeClass& shape):board(board), shape(shape) {
        menuBackground.setSize(sf::Vector2f(200, 600));
        menuButton.setSize(sf::Vector2f(200, 40));
        menuBackground.setFillColor(sf::Color(80,80,80,150));
        menuButtonSelected.setSize(sf::Vector2f(200, 40));
        menuButtonSelected.setFillColor(sf::Color(200,200,200,150));

        menuDieceBoard.setSize(sf::Vector2f(200, 200));
        menuDieceBoard.setFillColor(sf::Color(200,200,200,255));

        for (int i=0;i<6;i++){
            std::string filename="kosc"+std::to_string(i)+".png";
            dieceVisual[i].diece_texture.loadFromFile(filename);
            dieceVisual[i].diece_sprite.setTexture(dieceVisual[i].diece_texture);
            //dieceVisual[i].diece_sprite.setOrigin(dieceVisual[i].diece_sprite.getLocalBounds().width / 2, dieceVisual[i].diece_sprite.getLocalBounds().height / 2);
            dieceVisual[i].diece_sprite.setScale(sf::Vector2f(0.12f, 0.12f));
        }
        for (int i=0; i<4; i++){
        std::string filename_c="kursor"+std::to_string(i)+".png";
        cursorVisual[i].cursor_texture.loadFromFile(filename_c);
        cursorVisual[i].cursor_sprite.setTexture(cursorVisual[i].cursor_texture);
        cursorVisual[i].cursor_sprite.setScale(sf::Vector2f(0.25f, 0.25f));
        }
    }

void MenuClass::drawShapes(sf::RenderWindow& window) {

    // Load a sprite to display
            menuBackground.setPosition(600,0);
            window.draw(menuBackground);
            menuDieceBoard.setPosition(600,50);
            window.draw(menuDieceBoard);

            dieceVisual[board.checkDiece()].diece_sprite.setPosition(650+board.checkDieceCoord().first,100+board.checkDieceCoord().second);
            dieceVisual[board.checkDiece()].diece_sprite.setRotation(board.checkDieceRotation());
            window.draw(dieceVisual[board.checkDiece()].diece_sprite);

            //kolory przyciskow
            switch (board.getPlayerTurn()){
                case 0://czerwony
                    //menuBackground.setFillColor(sf::Color(200,80,80,150));
                    menuButton.setFillColor(sf::Color(220,100,100,255));
                    break;
                case 1://niebieski
                    //menuBackground.setFillColor(sf::Color(80,80,210,150));
                    menuButton.setFillColor(sf::Color(100,100,230,255));
                    break;
                case 2://zielony
                    //menuBackground.setFillColor(sf::Color(80,200,150,150));
                    menuButton.setFillColor(sf::Color(100,220,170,255));
                    break;
                case 3://zolty
                    //menuBackground.setFillColor(sf::Color(180,180,0,150));
                    menuButton.setFillColor(sf::Color(200,200,0,255));
                    break;
            }

            //kursor
            cursorVisual[board.getPlayerTurn()].cursor_sprite.setPosition(board.getCoordPawn(board.getPlayerTurn(),select).first*shape.getScale()+shape.getPawn_x_offset()+30, board.getCoordPawn(board.getPlayerTurn(),select).second*shape.getScale()+shape.getPawn_y_offset()+70);
            window.draw(cursorVisual[board.getPlayerTurn()].cursor_sprite);


            for (int i=0;i<=3;i++){
                menuButton.setPosition(600,300+50*i);
                window.draw(menuButton);
            }
            menuButtonSelected.setPosition(600,300+50*select);
            if (isMenuActive){
                window.draw(menuButtonSelected);
            }

    //text
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);

    text.setString("Pionek 1");
    text.setPosition(605,305);
    window.draw(text);

    text.setString("Pionek 2");
    text.setPosition(605,355);
    window.draw(text);

    text.setString("Pionek 3");
    text.setPosition(605,405);
    window.draw(text);

    text.setString("Pionek 4");
    text.setPosition(605,455);
    window.draw(text);

    }

void MenuClass::selecton_decrase(){
        if (select>0)
            select=select-1;
        else
            select=3;
    }

void MenuClass::selecton_incrase(){
        if (select<3)
            select=select+1;
        else
            select=0;
    }

bool MenuClass::getIsMenuActive(){
    return isMenuActive;
}

void MenuClass::MenuActivate(){
    isMenuActive=true;
}

void MenuClass::MenuDeactivate(){
    isMenuActive=false;
}

short MenuClass::getSelection(){
    return select;
}
