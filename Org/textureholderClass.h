#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <unordered_map> 
#include <memory>

class TextureHolder{
    private:
        std::unordered_map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap;
    public: 
        void               load(Textures::ID, const std::string& filename);
        sf::Texture&       get(Textures::ID);
        const sf::Texture& get(Textures::ID) const;
};


#endif //END TEXTUREHOLDER_H