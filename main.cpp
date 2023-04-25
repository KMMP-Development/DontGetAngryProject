#include <SFML/Graphics.hpp>
#include "shape.h"
#include "menu.h"

int main()
{

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Chinczyk v1"/*,sf::Style::Fullscreen*/);
    ShapeClass shape;
    MenuClass menu;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        //Draw the sprite
        shape.drawShapes(app);
        menu.drawShapes(app);
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
