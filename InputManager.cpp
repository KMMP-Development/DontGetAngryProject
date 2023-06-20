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
            if (event.type == sf::Event::MouseButtonReleased){
                if (event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(app);
                    std::cout<<"x: \t"<<mousePosition.x<<"y: \t"<<mousePosition.y<<std::endl;
                }
            }
            if (event.type == sf::Event::KeyPressed){
                //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                if (event.key.code == sf::Keyboard::Up){
                        //std::cout<<"up "<<std::endl;
                    menu.selecton_decrase();
                    //std::cout<<"zolty:     "<<board.getPawnFieldRealId(0,0)<<"\tprzesuniety: "<<board.getPawnFieldPersonalId(0,0)<<std::endl;
                    //std::cout<<"niebieski: "<<board.getPawnFieldRealId(1,0)<<"\tprzesuniety: "<<board.getPawnFieldPersonalId(1,0)<<std::endl;
                    //std::cout<<"zielony:   "<<board.getPawnFieldRealId(2,0)<<"\tprzesuniety: "<<board.getPawnFieldPersonalId(2,0)<<std::endl;
                    //std::cout<<"czerwony:  "<<board.getPawnFieldRealId(3,0)<<"\tprzesuniety: "<<board.getPawnFieldPersonalId(3,0)<<std::endl<<std::endl;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    menu.selecton_incrase();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
                    if (menu.getIsMenuActive()){
                        std::cout<<"enter ";
                        board.movePawn(board.getPlayerTurn(),menu.getSelection(),board.throwDiece());
                        board.nextPlayerTurn();
                        //menu.MenuDeactivate();
                    }
                }
            }
        }
}
