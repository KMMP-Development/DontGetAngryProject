struct Player{
    std::vector<std::pair<int, int>> coords_home;
    std::vector<std::pair<int, int>> coords_meta;
    std::vector<std::pair<int, int>> coords_start;
    sf::Texture pawn_texture;
    sf::Sprite pawn_sprite;
    sf::Color color;
};

class ShapeClass {
private:
    sf::RectangleShape rect;
    sf::CircleShape circle;
    float scale=50;
    int x_offset=0;
    int y_offset=300;
    //int y_offset=250;
    std::vector<std::pair<int, int>> coords = {{1,1},{2,1},{3,1},{4,1},{5,1},{5,2},{5,3},{5,4},{5,5},{6,5},{7,5},{7,4},{7,3},{7,2},{7,1},{8,1},{9,1},{10,1},{11,1},{11,0},{11,-1},{10,-1},{9,-1},{8,-1},{7,-1},{7,-2},{7,-3},{7,-4},{7,-5},{6,-5},{5,-5},{5,-4},{5,-3},{5,-2},{5,-1},{4,-1},{3,-1},{2,-1},{1,-1},{1,0}};
    Player player[4];

public:
    ShapeClass() {
        rect.setSize(sf::Vector2f(40, 40));
        rect.setFillColor(sf::Color(200,200,200,100));
        circle.setRadius(20);
        player[0].coords_home={{1,-5},{1,-4},{2,-5},{2,-4}};    //lewy gorny
        player[1].coords_home={{11,-5},{11,-4},{10,-5},{10,-4}};    //prawy gorny
        player[2].coords_home={{1,4},{1,5},{2,4},{2,5}};    //lewy dolny
        player[3].coords_home={{11,4},{11,5},{10,4},{10,5}};    //prawy dolny
        player[0].coords_meta={{2,0},{3,0},{4,0},{5,0}};
        player[1].coords_meta={{6,-4},{6,-3},{6,-2},{6,-1}};
        player[2].coords_meta={{6,4},{6,3},{6,2},{6,1}};
        player[3].coords_meta={{10,0},{9,0},{8,0},{7,0}};
        player[0].coords_start={{1,4}};
        player[1].coords_start={{7,0}};
        player[2].coords_start={{5,10}};
        player[3].coords_start={{11,6}};

        player[0].color=sf::Color(180,180,0,200);
        player[1].color=sf::Color(80,80,210,200);
        player[2].color=sf::Color(200,80,80,200);
        player[3].color=sf::Color(80,200,150,200);
    }

    void drawShapes(sf::RenderWindow& window) {
    // Load a sprite to display

        sf::Texture texture;
        texture.loadFromFile("background.jpg");
        sf::Sprite background(texture);
        window.draw(background);
    //pola
        rect.setFillColor(sf::Color(200,200,200,100));
        for (auto const& coord : coords) {
            rect.setPosition(coord.first*scale+x_offset, coord.second*scale+y_offset);
            window.draw(rect);
        }
    //pola startowe i mety
        for (int i=0;i<4;i++){
            rect.setFillColor(player[i].color);
            for (auto const& coord : player[i].coords_home) {
                rect.setPosition(coord.first*scale+x_offset, coord.second*scale+y_offset);
                window.draw(rect);
            }
            for (auto const& coord : player[i].coords_meta) {
                rect.setPosition(coord.first*scale+x_offset, coord.second*scale+y_offset);
                window.draw(rect);
            }
        circle.setFillColor(player[i].color);
        circle.setPosition(player[i].coords_start[0].first*scale+x_offset, player[i].coords_start[0].second*scale+y_offset-250);
        window.draw(circle);
        }


        //pionki
        for (int i=0;i<4;i++){
            std::string filename="pionek"+std::to_string(i+1)+".png";
            player[i].pawn_texture.loadFromFile(filename);
            player[i].pawn_sprite.setTexture(player[i].pawn_texture);
            player[i].pawn_sprite.setScale(sf::Vector2f(0.26f*scale/50, 0.26f*scale/50));

            for (int j=0; j<4;j++){
                player[i].pawn_sprite.setPosition(player[i].coords_home[j].first*scale+x_offset-10, player[i].coords_home[j].second*scale+y_offset-65);
                //player[i].pawn_sprite.setPosition(j*50,100+100*i);//pozycje testowe --------------------------------------------------------usun
                window.draw(player[i].pawn_sprite);
            }
        }
    }
};

