#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "menu.hpp"


class InputManager
{
    public:

        InputManager(sf::RenderWindow& window, MenuClass& menu);
        virtual ~InputManager();
        void processEvents();

    private:
        sf::RenderWindow& app;
        MenuClass& menu;

};

#endif // INPUTMANAGER_HPP
