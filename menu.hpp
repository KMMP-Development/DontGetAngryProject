#ifndef MENU_HPP
#define MENU_HPP
#include <SFML/Graphics.hpp>
#include "Board.hpp"
#include <iostream>
#include "shape.hpp"
#include "Sounds.hpp"

struct DieceVisual{
    sf::Texture diece_texture;
    sf::Sprite diece_sprite;
    sf::Color color;
};

struct CursorVisual{
    sf::Texture cursor_texture;
    sf::Sprite cursor_sprite;
};

class MenuClass {
private:
    sf::RectangleShape menuBackground;
    sf::RectangleShape menuButton;
    sf::RectangleShape menuButtonSelected;
    sf::RectangleShape menuDieceBoard;
    short select=0;
    sf::Font font;
    sf::Text text;
    bool isMenuActive=true;
    DieceVisual dieceVisual[6];
    Board &board;
    ShapeClass &shape;
    CursorVisual cursorVisual[4];
    Sound sound;

public:
    MenuClass(Board& board, ShapeClass& shape);
    void drawShapes(sf::RenderWindow& window);
    void selecton_decrase();
    void selecton_incrase();
    void selectionAccept();
    bool getIsMenuActive();
    void MenuActivate();
    void MenuDeactivate();
    short getSelection();
};
#endif
