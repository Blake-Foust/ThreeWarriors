#ifndef GAME_H
#define GAME_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
//#include "textureholderClass.h"
#include "ResourceHolder.hpp"

namespace Textures{
    enum ID{
        LandScape,
        Character,
        Missile
    };
};

namespace Audios{
    enum ID{
        Music
    };
};




class Game{
    public:
        Game();
        void run();

       ResourceHolder<sf::Texture, Textures::ID> textures;
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
       sf::Sprite mBackground;
       sf::RenderWindow mWindow;
       

};
#endif
