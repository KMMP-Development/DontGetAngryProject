#include <SFML/Graphics.hpp>
#include "shape.hpp"
#include "menu.hpp"
#include "InputManager.hpp"
#include <iostream>



int main()
{

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Chinczyk v1"/*,sf::Style::Fullscreen*/);
    ShapeClass shape;
    MenuClass menu;
    sf::Clock clock;
    InputManager inputManager(app, menu);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events

        inputManager.processEvents();



        sf::Time elapsed=clock.restart();
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
