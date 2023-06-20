#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.hpp"
#include "Board.hpp"


class InputManager
{
    public:

        InputManager(sf::RenderWindow& window, MenuClass& menu, Board& board);
        virtual ~InputManager();
        void processEvents();

    private:
        sf::RenderWindow& app;
        MenuClass& menu;
        Board& board;
};

#endif // INPUTMANAGER_HPP
