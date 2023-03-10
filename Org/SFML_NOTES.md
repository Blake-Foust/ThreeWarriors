# SFML NOTES


### TABLE OF CONTENTS
- [Resources](#resources)
- [Graphics](#graphics)
- [Sound and Music](#sound-and-music)
- [Credits](#credits)

Real-time rendering
Double buffering
In game development, the term resource
denotes an external component, which the application loads during runtime. Another often used term for a resource is asset

## RESOURCES

Load resources at the start of game, not when they are needed.
When they are not needed anymore we free memory

### Graphics

- sf::Image uses RAM
- sf::Texture uses Graphics card
- sf::Shaders operate on graphics card build on OpenGL

### Sound and Music

- sf::Sound uses sf::Soundbuffer to load the 16bits of sound from hard disk	
- sf::Music load small chunks from hard disk for continuasly streaming


### RANDOM NOTES
- RAII describes the principle that resources are acquired in a class'
constructor and released in its destructor. Using Smart pointers
- Don't use std::Vector for storing things since it makes copies and it could create a new address if a new texture is stored which distrupts references and pointers
- std::move to transfer ownership of variable your pointing to. 

### Credits
http://gafferongames.com/game-physics/fix-your-timestep