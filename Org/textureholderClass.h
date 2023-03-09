#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map>

namespace Textures{
    enum ID: int{
        LandScape,
        Character,
        Missile
    };
};

namespace Audios{
    enum ID: int{
        Music
    };
};


class TextureHolder{
    
    std::unordered_map<Textures::ID,
                       std::unique_ptr<sf::Texture>> mTextureMap;
    void               load(Textures::ID, const std::string& filename);
    sf::Texture&       get(Textures::ID);
    const sf::Texture& get(Textures::ID) const;
};


#endif //END TEXTUREHOLDER_H