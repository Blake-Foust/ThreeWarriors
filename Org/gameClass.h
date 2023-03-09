#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game{
    public:
        Game();
        void run();
    private:
        //Player events
        void processEvents();
        //Update game
        void update(sf::Time);
        //ren
        void render();

        void handlePlayerInput(sf::Keyboard::Key, bool);
        
        bool mIsMovingUp,
            mIsMovingDown,
            mIsMovingLeft,
            mIsMovingRight;
            
    private:
       sf::Texture mTexture;
       sf::Sprite mPlayer; 
       sf::RenderWindow mWindow;

};
#endif
