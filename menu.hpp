#ifndef MENU_HPP
#define MENU_HPP
#include <SFML/Graphics.hpp>

class MenuClass {
private:
    sf::RectangleShape menuBackground;
    sf::RectangleShape menuButton;
    sf::RectangleShape menuButtonSelected;
    short select=1;
    sf::Font font;
    sf::Text text;
    bool isMenuActive=true;
public:
    MenuClass();
    void drawShapes(sf::RenderWindow& window);
    void selecton_decrase();
    void selecton_incrase();
    bool getIsMenuActive();
    void MenuActivate();
    void MenuDeactivate();
};
#endif
