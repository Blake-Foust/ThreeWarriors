#include <iostream>
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "player.h"

void PlayerMovement(char& keyBoard){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        
      
    }
}




int main(){

    sf::VideoMode::getFullscreenModes();
    sf::RenderWindow window(sf::VideoMode(1200,800), "Night Night",sf::Style::Resize);

    sf::Music backgroundNoise;
    if(!backgroundNoise.openFromFile("sounds/night.wav"))
        return -1;
    
    backgroundNoise.play();
   
     
    sf::Texture textureBackground;
    if(!textureBackground.loadFromFile("assets/backgrounds/PNG/game_background_3/game_background_3.1.png")){
        std::cout << "Could not load background texture" << std::endl;
    }
    sf::Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0,0);

    //For Testing purposes
    sf::Texture player;
    if(!player.loadFromFile("assets/heroes/Pink_Monster/Pink_Monster.png")){
        std::cout << "Could not load Pink_Monster" << std::endl;
    }
    sf::Sprite pmSprite;
    pmSprite.setTexture(player);
    pmSprite.setPosition(0,0);

    
    
    sf::View worldView(window.getDefaultView());

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(spriteBackground);
        window.display();

    }
    return 0;
}
