
class ShapeClass {
private:
    sf::RectangleShape rect;
    std::vector<std::pair<int, int>> coords = { {50, 50}, {100, 50}, {150, 50} };

public:
    ShapeClass() {
        rect.setSize(sf::Vector2f(40, 40));
        rect.setFillColor(sf::Color(200,200,200,100));
    }

    void drawShapes(sf::RenderWindow& window) {

    // Load a sprite to display
    sf::Texture texture;
    texture.loadFromFile("background.jpg");
    sf::Sprite background(texture);

    window.draw(background);
        for (auto const& coord : coords) {
            rect.setPosition(coord.first, coord.second);
            window.draw(rect);
        }

    }
};

