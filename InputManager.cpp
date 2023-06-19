#include "InputManager.hpp"

InputManager::InputManager(sf::RenderWindow& window, MenuClass& menu):app(window), menu(menu)
{

}

InputManager::~InputManager()
{

}

void InputManager::processEvents(){
    sf::Event event;
    while (app.pollEvent(event))
    {


            if (event.type == sf::Event::Closed)// Close window : exit
                app.close();
            if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(app);
                    std::cout<<"x: \t"<<mousePosition.x<<"y: \t"<<mousePosition.y<<std::endl;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                menu.selecton_decrase();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                menu.selecton_incrase();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                if (menu.getIsMenuActive()){
                    std::cout<<"enter ";
                    menu.MenuDeactivate();
                }
            }
        }
}
