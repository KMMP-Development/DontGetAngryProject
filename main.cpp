#include <SFML/Graphics.hpp>
#include "Shape.hpp"
#include "Menu.hpp"
#include "InputManager.hpp"
#include "Board.hpp"
#include <iostream>

#define resolution_x 800
#define resolution_y 600
//#define resolution_x 1024
//#define resolution_y 760


int main()
{

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(resolution_x, resolution_y), "Chinczyk v1"/*,sf::Style::Fullscreen*/);

    Board board;
    ShapeClass shape(board);
    MenuClass menu(board, shape);



    //sf::Clock clock;
    InputManager inputManager(app, menu, board);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events

        inputManager.processEvents();//obsluga klawiatury i myszy



        //sf::Time elapsed=clock.restart();
        // Clear screen
        app.clear();

        //Rysowanie spritow
        shape.drawShapes(app);
        menu.drawShapes(app);
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
