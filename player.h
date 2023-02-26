#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>


class Player{
private:
    sf::Sprite playerSprite;
    sf::Vector2i playerSource; 
    enum _Direction{Down, Left, Right, Up};


    float playerSpeed;
    sf::Clock pClok;
    sf::Time pTime;
    
public:
    Player(){};
    Player(sf::Texture&);
    ~Player();

    //Player Movement Functions
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    sf::Sprite getSprite() const;

};

#endif