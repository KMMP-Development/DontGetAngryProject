#include "menu.hpp"

MenuClass::MenuClass() {
        menuBackground.setSize(sf::Vector2f(200, 600));
        menuBackground.setFillColor(sf::Color(200,150,150,200));
        menuButton.setSize(sf::Vector2f(200, 40));
        menuButton.setFillColor(sf::Color(150,150,200,255));
        menuButtonSelected.setSize(sf::Vector2f(200, 40));
        menuButtonSelected.setFillColor(sf::Color(200,200,150,255));
    }

void MenuClass::drawShapes(sf::RenderWindow& window) {

    // Load a sprite to display
            menuBackground.setPosition(600,0);
            window.draw(menuBackground);

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

    text.setString("poddaj sie");
    text.setPosition(605,305);
    window.draw(text);

    text.setString("poddaj sie szybciej");
    text.setPosition(605,355);
    window.draw(text);

    text.setString("wyrzuc plansze");
    text.setPosition(605,405);
    window.draw(text);

    text.setString("zamknij drzwi");
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
