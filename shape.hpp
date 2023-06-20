#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Board.hpp"

struct PlayerVisual{
    sf::Texture pawn_texture;
    sf::Sprite pawn_sprite;
    sf::Color color;
};

class ShapeClass {
private:
    sf::RectangleShape rect;
    sf::CircleShape circle;
    float scale=50;//rozmiar pola w pikselach
    int x_offset=1*scale;
    int y_offset=1*scale;
    int pawn_x_offset=-10*scale/50;
    int pawn_y_offset=-65*scale/50;
    std::vector<std::pair<int, int>> coords = {{1,1},{2,1},{3,1},{4,1},{5,1},{5,2},{5,3},{5,4},{5,5},{6,5},{7,5},{7,4},{7,3},{7,2},{7,1},{8,1},{9,1},{10,1},{11,1},{11,0},{11,-1},{10,-1},{9,-1},{8,-1},{7,-1},{7,-2},{7,-3},{7,-4},{7,-5},{6,-5},{5,-5},{5,-4},{5,-3},{5,-2},{5,-1},{4,-1},{3,-1},{2,-1},{1,-1},{1,0}};
    PlayerVisual playerVisual[4];
    Board &board;


public:
    ShapeClass(Board& board);
    void drawShapes(sf::RenderWindow& window);
    float getScale();
    int getPawn_x_offset();
    int getPawn_y_offset();
};

#endif
