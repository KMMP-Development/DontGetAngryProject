#include "InputManager.hpp"

InputManager::InputManager(sf::RenderWindow& window, MenuClass& menu, Board& board):app(window), menu(menu), board(board)
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
            //mysz
            if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(app);
                    std::cout<<"x: \t"<<mousePosition.x<<"y: \t"<<mousePosition.y<<std::endl;
                    //board.testMetaFlagStatus();
                    board.testFlagStatus();
                    board.testMetaFlagStatus();
                    //std::cout<<"r: "<<board.getPawnFieldRealId(0,0)<<"\tb: "<<board.getPawnFieldRealId(1,0)<<std::endl;

                    //board.destroyPawn(1,1,2,2);//testowe do usuniecia (przy drugim uzyciu wyjdzie poza tablice fieldFlags bo pionek nie bedzie na sciezce
                }
            }
            //klawiatura
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                    menu.selecton_decrase();

                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    menu.selecton_incrase();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    if (menu.getIsMenuActive()){
                        menu.selectionAccept();
                    }
                }
            }
        }
}
