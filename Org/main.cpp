#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include "gameClass.h"


int main(){
  Game game;
  sf::Texture::getMaximumSize();//16384
  game.run(); 
}
