
class MenuClass {
private:
    sf::RectangleShape menuBackground;
    sf::RectangleShape menuButton;
    sf::RectangleShape menuButtonSelected;
    short select=1;

public:
    MenuClass() {
        menuBackground.setSize(sf::Vector2f(200, 600));
        menuBackground.setFillColor(sf::Color(200,150,150,200));
        menuButton.setSize(sf::Vector2f(200, 40));
        menuButton.setFillColor(sf::Color(150,150,200,255));
        menuButtonSelected.setSize(sf::Vector2f(200, 40));
        menuButtonSelected.setFillColor(sf::Color(200,200,150,255));
    }

    void drawShapes(sf::RenderWindow& window) {

    // Load a sprite to display
            menuBackground.setPosition(600,0);
            window.draw(menuBackground);

            for (int i=0;i<=3;i++){
                menuButton.setPosition(600,300+50*i);
                window.draw(menuButton);
            }
            menuButtonSelected.setPosition(600,300+50*select);
            window.draw(menuButtonSelected);

    //text
    /*
    sf::Text text;
    text.setFont(font);
    ...
    */

    }
};


