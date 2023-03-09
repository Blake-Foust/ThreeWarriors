#include "gameClass.h"
#include "textureholderClass.h"

Game::Game():mWindow(sf::VideoMode(600,400),"SFML GAME"),mTexture(),mPlayer(){
    TextureHolder texture;

    texture.load(Textures::Character,"Pink_Monster.png");
    
    
    if(!mTexture.loadFromFile("Pink_Monster.png")){
        std::cout << "Couldn't load PinkMonst.png\n";        
    }
    this->mPlayer.setTexture(mTexture);
    this->mPlayer.setPosition(100.f,100.f);
}

void Game::run(){
    sf::Clock clock;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(this->mWindow.isOpen()){
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while(timeSinceLastUpdate > TimePerFrame){
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        this->render();
    }
};

void Game::processEvents(){
   sf::Event event;
   while(mWindow.pollEvent(event)){
     switch(event.type){
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            this->mWindow.close();
            break;
     }
   } 
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed){
    if(key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if(key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if(key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if(key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}

void Game::update(sf::Time deltaTime){
    sf::Vector2f movement(0.f, 0.f);
    if(mIsMovingUp)
        movement.y -= 20.f;
    if(mIsMovingLeft)
        movement.x -= 20.f;
    if(mIsMovingRight)
        movement.x += 20.f;
    if(mIsMovingDown)
        movement.y += 20.f;
    
    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}
